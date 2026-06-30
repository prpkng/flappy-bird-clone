#include "app/application.hpp"
#include "math/vector2.hpp"

#include "Testscene.hpp"
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

struct transform {
	Vector2 position;
	Vector2 scale;
    float rotation;
};

struct velocity {
	float dx;
	float dy;
};


void TestScene::OnEnter()
{
	registry = new entt::registry();

	for (auto i = 0; i < 100; ++i) {
		const auto entity = registry->create();
        Vector2 pos((i % 10) * 40.0f, SDL_floorf(i / 10.f) * 40.0f);
		registry->emplace<transform>(entity, pos, Vector2::ONE, 0.0f);
        auto clr = SDL_HSVToRGB(i * 2.55f, 1.f, 1.f);
		registry->emplace<color>(entity, clr.r, clr.g, clr.b, clr.a);
	}
}

void TestScene::update(float delta)
{
}

void TestScene::render(float delta)
{
	auto renderer = application->get_renderer();
	SDL_SetRenderDrawColor(renderer, 255, 150, 150, 255);
	SDL_RenderClear(renderer);

	auto view = registry->view<const transform, const color>();
    view.each([renderer](const transform& trans, const color& color) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_FRect rect {trans.position.x, trans.position.y, 40, 40};
        SDL_RenderFillRect(renderer, &rect);
	});
}

void TestScene::OnExit()
{
	registry->clear();
	delete registry;
}
