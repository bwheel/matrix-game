#pragma once

#include <SDL.h>
#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {
class RenderSystem : ISystem {
private:
  SDL_Renderer *m_renderer;

public:
  RenderSystem(entt::registry &registry, SDL_Renderer *renderer) : ISystem(registry), m_renderer(renderer) {}
  void Process(float deltaTime);
};

} // namespace Systems
