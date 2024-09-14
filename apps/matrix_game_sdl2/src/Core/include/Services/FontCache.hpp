#pragma once
#include <iostream>
#include <unordered_map>

#include <SDL.h>
#include <SDL_ttf.h>

#include <Components/Appearance.hpp>
#include <Utils/Alphabet.hpp>

namespace Services {

struct FontGlyph {
  SDL_Texture *texture;
  int width;
  int height;
};

class FontCache {
private:
  SDL_Renderer *m_renderer;
  std::unordered_map<char, FontGlyph> m_textures;

public:
  FontCache(SDL_Renderer *renderer) : m_renderer(renderer) {}
  ~FontCache();
  bool LoadFont(const std::array<char, Utils::ALPHABET_SIZE> alphabet, const char *filePath, const Components::FontSize fontSize, SDL_Color &textColor);
  FontGlyph *Get(char key);
  FontGlyph *GetRandom();
};
} // namespace Services
