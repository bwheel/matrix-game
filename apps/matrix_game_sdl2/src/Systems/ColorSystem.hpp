#pragma once

#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {
class ColorSystem : ISystem {
public:
  ColorSystem(entt::registry &registry) : ISystem(registry) {}
  void Process(float deltaTime);
};

} // namespace Systems
