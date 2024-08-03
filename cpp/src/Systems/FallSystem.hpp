#pragma once

#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {

class FallSystem : public ISystem {
public:
  FallSystem() {};
  ~FallSystem() {};
  void Process(entt::registry &registry);
};

}; // namespace Systems
