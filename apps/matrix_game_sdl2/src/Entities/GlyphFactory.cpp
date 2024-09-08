
#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include <Appearance.hpp>
#include <GlyphFactory.hpp>
#include <Position.hpp>
#include <Velocity.hpp>

namespace Entities {

entt::entity GlyphFactory::CreateStandard(float x, float y) {
  entt::entity entity = m_registry.create();
  m_registry.emplace<Components::Position>(entity, x, y);
  m_registry.emplace<Components::Velocity>(entity, 0.0f, 25.0f);
  SDL_Color color = {r : 255, g : 255, b : 255, a : 255};
  m_registry.emplace<Components::Appearance>(entity, color, 'A', Components::FontSize::Medium);
  return entity;
}
} // namespace Entities
