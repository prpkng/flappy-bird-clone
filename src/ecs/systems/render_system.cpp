#include "ecs/systems/render_system.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/sprite.hpp"

#include <SDL3/SDL.h>


void RenderSystem::render(SDL_Renderer* renderer, entt::registry& registry)
{
	auto sprites_view = registry.view<Transform, Sprite>();
	for (auto &&[entity, transform, sprite]: sprites_view.each()) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		if (sprite.texture_handle == nullptr)
		{
			SDL_FRect rect{ transform.position.x, transform.position.y, 32, 32 };
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderRect(renderer, &rect);
			return;
		}

		SDL_FRect src_rect{0, 0, 32, 32};
		SDL_FRect dst_rect{ transform.position.x, transform.position.y, 32, 32 };
		SDL_RenderTexture(renderer, sprite.texture_handle, &src_rect, &dst_rect);

	}
}
