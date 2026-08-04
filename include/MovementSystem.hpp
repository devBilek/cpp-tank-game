#pragma once

#include "Bullet.hpp"
#include "BulletManager.hpp"
#include "Entity.hpp"
#include <vector>

class Bullet;
class Entity;
class MovementSystem final {
private:
    std::vector<Entity*>& entities;
    BulletManager* bulletManager;
public:
    MovementSystem(std::vector<Entity*>& entities, BulletManager* bulletManager);
    void update(const float& deltaTime);
};