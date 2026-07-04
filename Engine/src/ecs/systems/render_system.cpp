#include "ecs/systems/render_system.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/sprite.hpp"
#include "ecs/components/renderable.hpp"

#include "math/conversions.hpp"

#include <SDL3/SDL.h>


static void sdl_render_wrap_workaround(
	SDL_Renderer* renderer,
	SDL_Texture* texture_handle,
	Rect2 src,
	Vector2 position,
	Vector2 scale,
	float angle,
	const SDL_FPoint* pivot,
	SDL_FlipMode flip_mode,
	bool wrap = false) {

	float texture_w, texture_h;
	SDL_GetTextureSize(texture_handle, &texture_w, &texture_h);

	Vector2 accumulated_pos(0, 0);
	Vector2 cur_pos(Math::fmod(src.x, texture_w), Math::fmod(src.y, texture_h));
	Vector2 remaining_size(src.width, src.height);
	if (!wrap) remaining_size = Vector2(texture_w, texture_h);
	while (remaining_size.y > 0) {
		Vector2 remainder(0, texture_h - cur_pos.y);
		cur_pos.x = Math::fmod(src.x, texture_w);
		accumulated_pos.x = 0;
		remaining_size.x = src.width;
		while (remaining_size.x > 0) {
			LOG_INFO("Remaining {}", remaining_size.x);
			remainder.x = MIN(remaining_size.x, texture_w - cur_pos.x);

			Rect2 src(cur_pos, remainder);
			Rect2 dst(position + accumulated_pos, remainder);

			SDL_FRect sdl_src = Conversions::to_sdl_rect(src);
			SDL_FRect sdl_dst = Conversions::to_sdl_rect(dst);
			SDL_RenderTextureRotated(renderer, texture_handle, &sdl_src, &sdl_dst, angle, pivot, flip_mode);
			remaining_size.x -= remainder.x;
			accumulated_pos.x += remainder.x * scale.x;
			cur_pos.x = 0;
		}
		remaining_size.y -= remainder.y;
		accumulated_pos.y += remainder.y * scale.y;
		cur_pos.y = 0;
	}
}

void RenderSystem::render(SDL_Renderer* renderer, entt::registry& registry)
{
	registry.sort<Renderable>([](const Renderable& lhs, const Renderable& rhs) {
		return lhs.z_order < rhs.z_order;
	});

	auto sprites_view = registry.view<const Transform, const Renderable, const Sprite>();
	for (auto &&[entity, transform, renderable, sprite]: sprites_view.each()) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		if (sprite.texture_handle == nullptr)
		{
			SDL_FRect rect{ transform.position.x, transform.position.y, 32, 32 };
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderRect(renderer, &rect);
			return;
		}

		Vector2 position = transform.position;

		Vector2 size{};
		SDL_GetTextureSize(sprite.texture_handle, &size.x, &size.y);

		Rect2 src_rect(Vector2::ZERO, size);
		if (sprite.texture_region.has_value()) src_rect = sprite.texture_region.value();

		Rect2 dst_rect{ position - size * sprite.pivot * transform.scale, size * transform.scale };
		dst_rect = dst_rect.round();

		// Replace with switch maybe?
		auto mode = sprite.wrap_mode == TextureWrapMode::Wrap ? SDL_TEXTURE_ADDRESS_WRAP : SDL_TEXTURE_ADDRESS_CLAMP;
		SDL_SetTextureColorModFloat(sprite.texture_handle, 
			renderable.modulation.r, renderable.modulation.g, renderable.modulation.b);
		SDL_SetTextureAlphaModFloat(sprite.texture_handle, renderable.modulation.a);

		Vector2 rotation_pivot = dst_rect.size * sprite.pivot;
		SDL_FPoint sdl_pivot{ rotation_pivot.x, rotation_pivot.y };
		
		sdl_render_wrap_workaround(
			renderer,
			sprite.texture_handle,
			src_rect,
			position - size * sprite.pivot * transform.scale,
			transform.scale,
			transform.get_rotation_degrees(),
			&sdl_pivot,
			SDL_FLIP_NONE,
			sprite.wrap_mode == TextureWrapMode::Wrap);
	}
}
