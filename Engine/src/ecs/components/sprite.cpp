#include "sprite.hpp"
#include "ecs/components/renderable.hpp"

void Sprite::on_construct(entt::registry& registry, const entt::entity entity)
{
	if (registry.all_of<Renderable>(entity)) return;
	registry.emplace<Renderable>(entity);
}
