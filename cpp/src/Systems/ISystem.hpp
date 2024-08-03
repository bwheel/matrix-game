#pragma once

#include <entt/entt.hpp>
namespace Systems {
class ISystem {
public:
  ISystem() {}
  virtual ~ISystem() {};
  virtual void Process(entt::registry &registry) = 0;
};

} // namespace Systems
