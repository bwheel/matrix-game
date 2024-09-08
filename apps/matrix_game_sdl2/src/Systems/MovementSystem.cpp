#include <MovementSystem.hpp>

#include <iostream>

#include <Position.hpp>
#include <Velocity.hpp>

namespace Systems {
void MovementSystem::Process(float deltaTime) {

  auto view = m_registry.view<Components::Position, Components::Velocity>();

  for (auto entity : view) {
    auto &pos = view.get<Components::Position>(entity);
    auto &vel = view.get<Components::Velocity>(entity);

    pos.X += vel.Dx * deltaTime;
    pos.Y += vel.Dy * deltaTime;
  }
}

} // namespace Systems
