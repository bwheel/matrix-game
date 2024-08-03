#pragma once

#include <cstdint>

namespace Components {
struct RotationInterval {
  std::int32_t rotationInterval;
  std::uint32_t lastRotationMs;
};
} // namespace Components
