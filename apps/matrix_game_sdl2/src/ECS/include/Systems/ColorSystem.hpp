#pragma once

#include <entt/entt.hpp>

#include <Systems/ISystem.hpp>

namespace Systems {
class ColorSystem : public ISystem {
public:
  ColorSystem(entt::registry &registry) : ISystem(registry) {}
  void Process(float deltaTime);
};

} // namespace Systems
