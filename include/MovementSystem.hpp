#pragma once

#include "Bullet.hpp"
#include "Entity.hpp"
#include <vector>

class Bullet;
class Entity;
class MovementSystem final {
private:
    std::vector<Entity*>& entities;
    std::vector<std::unique_ptr<Bullet>>& bullets;
public:
    MovementSystem(std::vector<Entity*>& entities, std::vector<std::unique_ptr<Bullet>>& bullets);
    void update(const float& deltaTime);
};