#pragma once

#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {
class RotationSystem : ISystem {
public:
  RotationSystem(entt::registry &registry) : ISystem(registry) {}
  void Process(float deltaTime);
};

} // namespace Systems