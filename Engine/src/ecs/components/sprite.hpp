#pragma once

#include "math/rect2.hpp"

#include <optional>
#include <entt/entt.hpp>

struct SDL_Texture;

enum class TextureWrapMode {
	Clamp,
	Wrap,
};

enum class SpriteScaleMode {
	Stretch,
	Repeat,
};

struct Sprite {
	SDL_Texture* texture_handle;
	TextureWrapMode wrap_mode = TextureWrapMode::Clamp;

	std::optional<Rect2> texture_region = {};
	// Relative to sprite size, defines where the pivot is located
	// ZERO is top left
	Vector2 pivot = Vector2::ZERO;
	SpriteScaleMode scale_mode = SpriteScaleMode::Stretch;


	static void on_construct(entt::registry& registry, const entt::entity entity);
};