#pragma once
#include <array>

#include <SDL2/SDL.h>

namespace Components {
enum class FontSize : int { ExtraSmall = 8, Small = 12, Medium = 24, Large = 36, ExtraLarge = 48 };

constexpr std::array<FontSize, 5> ALL_FONT_SIZES = {
    FontSize::ExtraSmall, FontSize::Small, FontSize::Medium, FontSize::Large, FontSize::ExtraLarge,
};

struct Appearance {
  SDL_Color Color;
  SDL_Texture *Texture;
  FontSize Size;
  int TextWidth;
  int TextHeight;
};

} // namespace Components
