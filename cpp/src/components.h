#pragma once

#include <cstdint>
#include <string>
#include <tuple>

namespace Components {

struct Position2D {
  int x;
  int y;
};

struct Velocity2D {
  int dx;
  int dy;
};

struct Glyph {
  char character;
  std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> color;
};

struct RotationInterval {
  std::int32_t rotationInterval;
  std::uint32_t lastRotationMs;
};
}