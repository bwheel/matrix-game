#include <Services/FontCache.hpp>

#include <Components/Appearance.hpp>
#include <Utils/Alphabet.hpp>

namespace Services {

FontCache::~FontCache() {
  for (auto kvp : m_textures) {
    SDL_DestroyTexture(kvp.second.texture);
  }
  m_textures.clear();
}

bool FontCache::LoadFont(const char *filePath, const Components::FontSize fontSize, SDL_Color &textColor) {
  TTF_Font *font = TTF_OpenFont(filePath, static_cast<int>(fontSize));
  if (!font) {
    return false;
  }
  int textWidth = 0;
  int textHeight = 0;
  for (auto letter : Utils::ALPHABET()) {
    if (TTF_SizeText(font, &letter, &textWidth, &textHeight) != 0) {
      return false;
    }
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, &letter, textColor);

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);

    m_textures[letter] = {.texture = textTexture, .width = textWidth, .height = textHeight};
    SDL_FreeSurface(textSurface);
  }

  TTF_CloseFont(font);
  return true;
}
FontGlyph *FontCache::Get(char key) { return &m_textures[key]; }
} // namespace Services
