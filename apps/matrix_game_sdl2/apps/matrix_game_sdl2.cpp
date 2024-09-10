#include <iostream>
#include <memory>
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>
#include <entt/entt.hpp>

#include <Entities/GlyphFactory.hpp>
#include <Systems/ColorSystem.hpp>
#include <Systems/ISystem.hpp>
#include <Systems/MovementSystem.hpp>
#include <Systems/RenderSystem.hpp>
#include <Systems/RotationSystem.hpp>

void printSDL() {

  // Get SDL version at runtime
  SDL_version compiled;
  SDL_version linked;

  SDL_VERSION(&compiled);  // Macro that stores the version the program was compiled against
  SDL_GetVersion(&linked); // Function that returns the version of the library being used

  std::cout << "Compiled against SDL version: " << (int)compiled.major << "." << (int)compiled.minor << "." << (int)compiled.patch << std::endl;
  std::cout << "Linked against SDL version: " << (int)linked.major << "." << (int)linked.minor << "." << (int)linked.patch << std::endl;
}

int main() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Initialize SDL2_ttf
  if (TTF_Init() != 0) {
    std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("SDL with EnTT Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Load a font
  TTF_Font *font = TTF_OpenFont("resources/SpaceMono.ttf", 24); // Adjust font path and size as needed
  if (!font) {
    std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }

  const char *glyph = "M";
  int textWidth = 0;
  int textHeight = 0;
  if (TTF_SizeText(font, glyph, &textWidth, &textHeight) != 0) {
    std::cerr << "TTF_SizeText Error: " << TTF_GetError() << std::endl;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }
  std::cout << "textWidth: " << textWidth << " textHeight: " << textHeight << std::endl;
  SDL_Color textColor = {255, 255, 255, 255}; // White
  SDL_Surface *textSurface = TTF_RenderText_Solid(font, glyph, textColor);
  if (!textSurface) {
    std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_FreeSurface(textSurface);
  if (!textTexture) {
    std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }

  // Create EnTT registry
  entt::registry registry;
  Entities::GlyphFactory glyphFactory(registry);
  glyphFactory.CreateStandard(100, 100, textTexture, textWidth, textHeight);

  // Create Systems
  std::vector<std::unique_ptr<Systems::ISystem>> systems;
  systems.push_back(std::make_unique<Systems::ColorSystem>(registry));
  systems.push_back(std::make_unique<Systems::MovementSystem>(registry));
  systems.push_back(std::make_unique<Systems::RenderSystem>(registry, renderer));
  systems.push_back(std::make_unique<Systems::RotationSystem>(registry));

  bool isRunning = true;
  SDL_Event event;
  float currentTime;
  float deltaTime = 1.0f / 60.0f;
  while (isRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        isRunning = false;
      }
    }

    // Update systems
    for (auto &system : systems) {
      system->Process(deltaTime);
    }

    // Delay to simulate a 60 FPS game loop
    SDL_Delay(static_cast<Uint32>(deltaTime * 1000));
  }

  // Cleanup and quit SDL
  SDL_Quit();
  return 0;
}