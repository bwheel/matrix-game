
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <entt/entt.hpp>

#include <RenderSystem.hpp>
#include <components.h>
#include <globals.h>

namespace Systems {
void RenderSystem::Process(entt::registry &registry) {
  // SDL_Color color = {0, 255, 0, 255};
  // auto view = registry.view<Components::Position2D, Components::Glyph>();
  // for (auto entity : view) {
  //   auto &pos = view.get<Components::Position2D>(entity);
  //   auto &glyph = view.get<Components::Glyph>(entity);
  //   SDL_Surface *surface = TTF_RenderGlyph_Solid(font, glyph.character, color);
  //   if (surface == nullptr)
  //     continue;

  //   SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  //   SDL_FreeSurface(surface);
  //   if (texture == nullptr)
  //     continue;

  //   SDL_Rect dstRect = {pos.x, pos.y, Globals::FONT_SIZE, Globals::FONT_SIZE};
  //   SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
  //   SDL_DestroyTexture(texture);
}
}
} // namespace Systems