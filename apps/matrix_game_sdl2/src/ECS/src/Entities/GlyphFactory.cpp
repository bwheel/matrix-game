
#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include <Components/Appearance.hpp>
#include <Components/Position.hpp>
#include <Components/Velocity.hpp>
#include <Entities/GlyphFactory.hpp>

namespace Entities {

entt::entity GlyphFactory::CreateStandard(float x, float y, SDL_Texture *texture, int textWidth, int textHeight) {
  entt::entity entity = m_registry.create();
  m_registry.emplace<Components::Position>(entity, x, y);
  m_registry.emplace<Components::Velocity>(entity, 0.0f, 25.0f);
  SDL_Color color = {r : 255, g : 255, b : 255, a : 255};
  m_registry.emplace<Components::Appearance>(entity, color, texture, Components::FontSize::Medium, textWidth, textHeight);
  return entity;
}
} // namespace Entities
