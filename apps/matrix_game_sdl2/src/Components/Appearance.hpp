#pragma once
#include <cstdint>

#include <SDL2/SDL.h>
namespace Components {
enum class FontSize : int { Small = 12, Medium = 24, Large = 36, ExtraLarge = 48 };

struct Appearance {
  SDL_Color Color;
  char Value;
  FontSize Size;
};

} // namespace Components
