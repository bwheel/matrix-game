#include <iostream>
#include <memory>
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>
#include <entt/entt.hpp>

#include <Entities/GlyphFactory.hpp>
#include <Services/FontCache.hpp>
#include <Systems/ColorSystem.hpp>
#include <Systems/ISystem.hpp>
#include <Systems/MovementSystem.hpp>
#include <Systems/RenderSystem.hpp>
#include <Systems/RotationSystem.hpp>
#include <Utils/Alphabet.hpp>

void printSDL() {

  // Get SDL version at runtime
  SDL_version compiled;
  SDL_version linked;

  SDL_VERSION(&compiled);  // Macro that stores the version the program was compiled against
  SDL_GetVersion(&linked); // Function that returns the version of the library being used

  std::cout << "Compiled against SDL version: " << (int)compiled.major << "." << (int)compiled.minor << "." << (int)compiled.patch << std::endl;
  std::cout << "Linked against SDL version: " << (int)linked.major << "." << (int)linked.minor << "." << (int)linked.patch << std::endl;
}

void CreateStream(Entities::GlyphFactory glyphFactory, Services::FontCache fontCache, float x) {
  int lettersPerScreen = 600 / fontCache.Get('A')->height; // TODO better screen size
  int streamSize = rand() % lettersPerScreen + 1;
  int prevHeight = 50;
  for (int y = 0; y < streamSize; y++) {
    Services::FontGlyph *glyph = fontCache.GetRandom();
    int yPos = prevHeight + glyph->height;
    glyphFactory.CreateStandard(x, yPos, glyph->texture, glyph->width, glyph->height);
    prevHeight += glyph->height;
  }
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
  Services::FontCache fontCache(renderer);
  SDL_Color white = {255, 255, 255, 255}; // White
  fontCache.LoadFont(Utils::ALPHABET(), "resources/SpaceMono.ttf", Components::FontSize::Small, white);

  // Create EnTT registry
  entt::registry registry;
  Entities::GlyphFactory glyphFactory(registry);
  int x = 50;
  int y = 50;
  Services::FontGlyph *glyph = fontCache.GetRandom();
  // glyphFactory.CreateStandard(x, y, glyph->texture, glyph->width, glyph->height);

  for (auto letter : Utils::ALPHABET()) {
    CreateStream(glyphFactory, fontCache, 50);
    x += 50;
  }

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
        break;
      } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
        break;
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