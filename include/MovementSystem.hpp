#pragma once

#include "Entity.hpp"
#include <vector>

class Entity;
class MovementSystem final {
private:
    std::vector<Entity*>& entities;
public:
    MovementSystem(std::vector<Entity*>& entities);
    void update(const float& deltaTime);
};