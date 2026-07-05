#include "TestScene.hpp"

#include "app/application.hpp"
#include "math/vector2.hpp"
#include "math/rect2.hpp"

#include "ecs/events/key_events.hpp"
#include "ecs/components/transform.hpp"
#include "ecs/components/sprite.hpp"
#include "ecs/components/physics.hpp"
#include "ecs/components/player.hpp"
#include "ecs/components/renderable.hpp"

#include "components/parallax.hpp"


#include "game_settings.hpp"

#include <SDL3/SDL.h>

#include <random>

void TestScene::enter()
{
    auto& window = application->get_window();
    float aspect = window->size().aspect();
    Vector2 tex_size(VIEWPORT_SIZE.y * aspect, VIEWPORT_SIZE.y);

    LOG_INFO("Initializing render texture of size: {}", tex_size.round().to_string());

    auto renderer = application->get_renderer();

    SDL_SetRenderLogicalPresentation(
        renderer,
        144, 256,
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );


	registry.clear();

    auto surface = SDL_LoadPNG("assets/bird1.png");
    auto texture = SDL_CreateTextureFromSurface(application->get_renderer(), surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

    SDL_DestroySurface(surface);

    registry.ctx().emplace<GameSettings>();

    {
        // Create player
        const auto player_entity = registry.create();
        registry.emplace<Transform>(player_entity, VIEWPORT_SIZE / 2.0f, Vector2::ONE, 0.0f);
        registry.emplace<PhysicsObject>(player_entity);
        registry.emplace<CollisionShape>(player_entity, Rect2(-4, -4, 8, 8));

        registry.emplace<Player>(player_entity);

        auto& spr = registry.emplace<Sprite>(player_entity, texture);
        spr.pivot = Vector2(0.5f, 0.5f);
        spr.texture_region = Rect2(0, 0, 32, 32);

        dispatcher.sink<KeyDownEvent>().connect<&PlayerSystem::on_key_down>(player_system);
    }


    {
        surface = SDL_LoadPNG("assets/background.png");
        texture = SDL_CreateTextureFromSurface(application->get_renderer(), surface);
        SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
        SDL_DestroySurface(surface);

        const auto bg = registry.create();
        registry.emplace<Transform>(bg);
        registry.emplace<Renderable>(bg, -10);
        auto& spr = registry.emplace<Sprite>(bg, texture);
        spr.wrap_mode = TextureWrapMode::Wrap;
        spr.texture_region = Rect2(Vector2::ZERO, VIEWPORT_SIZE);
        registry.emplace<Parallax>(bg, 10.0f);
    }

    pipe_system.setup(renderer, dispatcher);
}

void TestScene::update(float delta)
{
    physics_system.update(delta, registry);
    player_system.update(delta, registry, dispatcher);
    pipe_system.update(delta, registry, dispatcher);
}

void TestScene::render(float delta)
{
    auto& window = application->get_window();
	auto renderer = application->get_renderer();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    render_system.render(renderer, registry);
    if (debug_draw)
        physics_system.debug_render(renderer, registry);

}

void TestScene::on_event(const WindowEvent& event)
{
    switch (event.type) {
    case EventType::KeyPress: 
        dispatcher.trigger(KeyDownEvent { registry, event.key.physical_code, event.key.key_code });

        if (event.key.physical_code == PhysicalKeyCode::D) debug_draw = !debug_draw;
        break;
    case EventType::KeyRelease: 
        dispatcher.trigger(KeyUpEvent { registry, event.key.physical_code, event.key.key_code });
        break;
    }
}

void TestScene::exit()
{
	registry.clear();
}