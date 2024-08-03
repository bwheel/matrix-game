#include <cstdlib>
#include <ctime>
#include <iostream>
#include <optional>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <entt/entt.hpp>

#include <components.h>
#include <globals.h>
#include <systems/update_position.h>

void renderLetters(SDL_Renderer *renderer, TTF_Font *font, entt::registry &registry) {
  SDL_Color color = {0, 255, 0, 255};
  auto view = registry.view<Components::Position2D, Components::Glyph>();
  for (auto entity : view) {
    auto &pos = view.get<Components::Position2D>(entity);
    auto &glyph = view.get<Components::Glyph>(entity);
    SDL_Surface *surface = TTF_RenderGlyph_Solid(font, glyph.character, color);
    if (surface == nullptr)
      continue;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr)
      continue;

    SDL_Rect dstRect = {pos.x, pos.y, Globals::FONT_SIZE, Globals::FONT_SIZE};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
  }
}

std::optional<TTF_Font *> initFont(int fontSize) {
  TTF_Font *font = TTF_OpenFont("assets/FiraCode.ttf", fontSize);
  if (font == nullptr) {
    return std::nullopt;
  }

  return std::optional<TTF_Font *>(font);
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0) {
    std::cout << "Error in init " << SDL_GetError() << "\n";
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("Matrix Rainfall", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  auto font = initFont(Globals::FONT_SIZE);

  if (!font.has_value()) {
    std::cout << "Error in open font " << SDL_GetError() << "\n";
    SDL_Quit();
    TTF_Quit();
    return 1;
  }
  std::srand(std::time(nullptr));
  entt::registry registry;

  for (int i = 0; i < Globals::NUM_COLUMNS; ++i) {
    auto entity = registry.create();
    registry.emplace<Components::Position2D>(entity, i * Globals::FONT_SIZE, rand() % Globals::SCREEN_HEIGHT);
    registry.emplace<Components::Velocity2D>(entity, 0, 1 + rand() % 5);
    registry.emplace<Components::Glyph>(entity, 'A' + (rand() % 26));
  }

  bool quit = false;
  SDL_Event e;
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    Systems::updatePosition(registry);
    renderLetters(renderer, font.value(), registry);

    SDL_RenderPresent(renderer);
    SDL_Delay(10); // Control the speed of the animation
  }

  TTF_CloseFont(font.value());
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();

  return 0;
}