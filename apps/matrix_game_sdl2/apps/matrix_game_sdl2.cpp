#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <entt/entt.hpp>

#include <GlyphFactory.hpp>

#include <ColorSystem.hpp>
#include <ISystem.hpp>
#include <MovementSystem.hpp>
#include <RenderSystem.hpp>
#include <RotationSystem.hpp>

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

  // Create EnTT registry
  entt::registry registry;
  Entities::GlyphFactory glyphFactory(registry);
  glyphFactory.CreateStandard(100, 100);

  // Create Systems
  Systems::ColorSystem colorSystem(registry);
  Systems::MovementSystem movementSystem(registry);
  Systems::RenderSystem renderSystem(registry, renderer);
  Systems::RotationSystem rotationSystem(registry);

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
    movementSystem.Process(deltaTime);
    rotationSystem.Process(deltaTime);
    colorSystem.Process(deltaTime);
    renderSystem.Process(deltaTime);

    // Delay to simulate a 60 FPS game loop
    SDL_Delay(static_cast<Uint32>(deltaTime * 1000));
  }

  // Cleanup and quit SDL
  SDL_Quit();
  return 0;
}