#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <entt/entt.hpp>

// Define screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FONT_SIZE = 24;
const int NUM_COLUMNS = SCREEN_WIDTH / FONT_SIZE;

// Define components
struct Position {
  int x, y;
};

struct Velocity {
  int dy;
};

struct Glyph {
  char character;
};

void renderLetters(SDL_Renderer *renderer, TTF_Font *font, entt::registry &registry) {
  SDL_Color color = {0, 255, 0, 255};
  auto view = registry.view<Position, Glyph>();
  for (auto entity : view) {
    auto &pos = view.get<Position>(entity);
    auto &glyph = view.get<Glyph>(entity);

    SDL_Surface *surface = TTF_RenderGlyph_Solid(font, glyph.character, color);
    if (surface == nullptr)
      continue;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr)
      continue;

    SDL_Rect dstRect = {pos.x, pos.y, FONT_SIZE, FONT_SIZE};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
  }
}

void updateLetters(entt::registry &registry) {
  auto view = registry.view<Position, Velocity>();
  for (auto entity : view) {
    auto &pos = view.get<Position>(entity);
    auto &vel = view.get<Velocity>(entity);

    pos.y += vel.dy;
    if (pos.y > SCREEN_HEIGHT) {
      pos.y = -FONT_SIZE;
      auto &glyph = registry.get<Glyph>(entity);
      glyph.character = 'A' + (rand() % 26);
    }
  }
}

TTF_Font *loadFont(int fontSize) {
  TTF_Font *font = TTF_OpenFont("assets/font.ttf", fontSize);
  if (font == nullptr) {
    // Try loading some common system fonts
    font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", fontSize);
    if (font == nullptr) {
      font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeSans.ttf", fontSize);
      if (font == nullptr) {
        font = TTF_OpenFont("/Library/Fonts/Arial.ttf", fontSize);
        if (font == nullptr) {
          font = TTF_OpenFont("C:\\Windows\\Fonts\\arial.ttf", fontSize);
        }
      }
    }
  }
  return font;
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0) {
    std::cout << "Error in init " << SDL_GetError() << "\n";
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("Matrix Rainfall", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  TTF_Font *font = loadFont(FONT_SIZE);
  if (font == nullptr) {
    std::cout << "Error in open font " << SDL_GetError() << "\n";
    SDL_Quit();
    TTF_Quit();
    return 1;
  }

  std::srand(std::time(nullptr));
  entt::registry registry;

  for (int i = 0; i < NUM_COLUMNS; ++i) {
    auto entity = registry.create();
    registry.emplace<Position>(entity, i * FONT_SIZE, rand() % SCREEN_HEIGHT);
    registry.emplace<Velocity>(entity, 10 + rand() % 5);
    registry.emplace<Glyph>(entity, 'A' + (rand() % 26));
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

    updateLetters(registry);
    renderLetters(renderer, font, registry);

    SDL_RenderPresent(renderer);
    SDL_Delay(10); // Control the speed of the animation
  }

  TTF_CloseFont(font);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();

  return 0;
}