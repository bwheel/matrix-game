#include <RenderSystem.hpp>

#include <iostream>

#include <Appearance.hpp>
#include <Position.hpp>

namespace Systems {
void RenderSystem::Process(float deltaTime) {

  // clear screen
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  auto view = this->m_registry.view<Components::Position, Components::Appearance>();

  for (auto entity : view) {
    auto &pos = view.get<Components::Position>(entity);
    auto &renderable = view.get<Components::Appearance>(entity);
    // TODO: We will need to change later to font.
    // For now we have an example size of 50x50.
    SDL_Rect rect = {static_cast<int>(pos.X), static_cast<int>(pos.Y), 50, 50};
    SDL_SetRenderDrawColor(m_renderer, renderable.Color.r, renderable.Color.g, renderable.Color.b, renderable.Color.a);
    SDL_RenderFillRect(m_renderer, &rect);
  }

  // Present the rendered frame
  SDL_RenderPresent(m_renderer);
}
} // namespace Systems
