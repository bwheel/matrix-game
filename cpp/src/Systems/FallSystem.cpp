

#include <entt/entt.hpp>

#include <FallSystem.hpp>
#include <components.h>
#include <globals.h>

namespace Systems {

void FallSystem::Process(entt::registry &registry) {
  auto view = registry.view<Components::Position2D, Components::Velocity2D>();
  for (auto entity : view) {
    auto &pos = view.get<Components::Position2D>(entity);
    auto &vel = view.get<Components::Velocity2D>(entity);

    pos.y += vel.dy;
    if (pos.y > Globals::SCREEN_HEIGHT) {
      pos.y = -Globals::FONT_SIZE;
      auto &glyph = registry.get<Components::Glyph>(entity);
      glyph.character = 'A' + (rand() % 26);
    }
  }
}

} // namespace Systems
