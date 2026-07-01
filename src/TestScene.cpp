#include "app/application.hpp"
#include "math/vector2.hpp"

#include "ecs/events/key_events.hpp"
#include "ecs/components/transform.hpp"
#include "ecs/components/sprite.hpp"

#include "TestScene.hpp"
#include <SDL3/SDL.h>

SDL_Color SDL_HSVToRGB(float h, float s, float v) {
    SDL_Color rgb;
    rgb.a = 255; 

    if (s <= 0.0f) {
        Uint8 gray = (Uint8)(v * 255.0f);
        rgb.r = gray;
        rgb.g = gray;
        rgb.b = gray;
        return rgb;
    }

    if (h >= 360.0f) h = fmodf(h, 360.0f);
    if (h < 0.0f) h = 360.0f + fmodf(h, 360.0f);

    float hh = h / 60.0f;
    int i = (int)hh;
    float ff = hh - i;

    float p = v * (1.0f - s);
    float q = v * (1.0f - (s * ff));
    float t = v * (1.0f - (s * (1.0f - ff)));

    float r = 0, g = 0, b = 0;

    switch (i) {
    case 0: r = v; g = t; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = t; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = t; g = p; b = v; break;
    case 5: default: r = v; g = p; b = q; break;
    }

    rgb.r = (Uint8)(r * 255.0f);
    rgb.g = (Uint8)(g * 255.0f);
    rgb.b = (Uint8)(b * 255.0f);

    return rgb;
}

struct color {
	Uint8 r, g, b, a;
};


struct velocity {
	float dx;
	float dy;
};


void TestScene::enter()
{
	registry.clear();

    auto surface = SDL_LoadPNG("assets/bird1.png");
    auto texture = SDL_CreateTextureFromSurface(application->get_renderer(), surface);

    SDL_DestroySurface(surface);

	for (auto i = 0; i < 100; ++i) {
		const auto entity = registry.create();
        Vector2 pos((i % 10) * 40.0f, SDL_floorf(i / 10.f) * 40.0f);
		registry.emplace<Transform>(entity, pos, Vector2::ONE, 0.0f);
        //auto clr = SDL_HSVToRGB(i * 2.55f, 1.f, 1.f);
		//registry.emplace<color>(entity, clr.r, clr.g, clr.b, clr.a);
        registry.emplace<Sprite>(entity, texture);
	}
}

void TestScene::update(float delta)
{
    physics_system.update(delta, registry);
}

void TestScene::render(float delta)
{
	auto renderer = application->get_renderer();
	SDL_SetRenderDrawColor(renderer, 255, 150, 150, 255);
	SDL_RenderClear(renderer);

    render_system.render(renderer, registry);
}

void TestScene::on_event(const WindowEvent& event)
{
    switch (event.type) {
    case EventType::KeyPress: 
        dispatcher.trigger(KeyDownEvent { event.key.physical_code, event.key.key_code });
        break;
    case EventType::KeyRelease: 
        dispatcher.trigger(KeyUpEvent { event.key.physical_code, event.key.key_code });
        break;
    
    }
}

void TestScene::exit()
{
	registry.clear();
}
