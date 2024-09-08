#pragma once

#include <entt/entt.hpp>
namespace Systems {

class ISystem {
protected:
  entt::registry &m_registry;

public:
  ISystem(entt::registry &registry) : m_registry(registry) {}
  virtual void Process(float deltaTime) = 0;
};

} // namespace Systems
