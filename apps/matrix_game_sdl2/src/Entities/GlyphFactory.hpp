#pragma once
#include <entt/entt.hpp>

#include <Position.hpp>

namespace Entities {

class GlyphFactory {
private:
  entt::registry &m_registry;

public:
  GlyphFactory(entt::registry &registry) : m_registry(registry) {};
  entt::entity CreateStandard(float x, float y);
};

} // namespace Entities
