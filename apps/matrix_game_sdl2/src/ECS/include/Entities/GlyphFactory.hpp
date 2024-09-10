#pragma once
#include <SDL2/SDL.h>
#include <entt/entt.hpp>

namespace Entities {

class GlyphFactory {
private:
  entt::registry &m_registry;

public:
  GlyphFactory(entt::registry &registry) : m_registry(registry) {};
  entt::entity CreateStandard(float x, float y, SDL_Texture *texture, int textWidth, int textHeight);
};

} // namespace Entities
