#pragma once

#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {
class MovementSystem : ISystem {
public:
  MovementSystem(entt::registry &registry) : ISystem(registry) {}
  void Process(float deltaTime);
};

} // namespace Systems
