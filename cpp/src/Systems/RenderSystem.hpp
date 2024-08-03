#pragma once

#include <entt/entt.hpp>

#include <ISystem.hpp>

namespace Systems {
class RenderSystem : public ISystem {
public:
  RenderSystem() {};
  ~RenderSystem() {};
  void Process(entt::registry &registry);
};
} // namespace Systems
