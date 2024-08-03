#pragma once

#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {
class RotationSystem : public ISystem {
public:
  RotationSystem() {};
  ~RotationSystem() {};
  void Process(entt::registry &registry);
};
} // namespace Systems
