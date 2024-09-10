#pragma once

#include <entt/entt.hpp>

#include <Systems/ISystem.hpp>

namespace Systems {
class RotationSystem : public ISystem {
public:
  RotationSystem(entt::registry &registry) : ISystem(registry) {}
  void Process(float deltaTime);
};

} // namespace Systems
