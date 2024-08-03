#pragma once

#include <map>
#include <optional>
#include <vector>

#include <SDL2/SDL_ttf.h>

namespace Components {

enum class FontSizes { XS = 8, S = 10, M = 14, L = 18, XL = 22 };
static const FontSizes All[] = {FontSizes::XS, FontSizes::S, FontSizes::M, FontSizes::L, FontSizes::XL};

struct GameFonts {
  std::map<FontSizes, TTF_Font *> fonts;
};

// TODO: call from create GameFonts entity
std::optional<GameFonts> initGameFonts() {
  GameFonts gameFonts = GameFonts();
  for (auto fontSize : All) {
    TTF_Font *font = TTF_OpenFont("assets/FiraCode.ttf", static_cast<int>(fontSize));
    if (font == nullptr) {
      return std::nullopt;
    }
    gameFonts.fonts[fontSize] = font;
  }
  return gameFonts;
}

} // namespace Components
