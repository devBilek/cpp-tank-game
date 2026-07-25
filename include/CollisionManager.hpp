#pragma once

#include "Entity.hpp"
class Entity;
class CollisionManager final {
public:
    static bool checkCollision(const Entity* entity1, const Entity* entity2);
};