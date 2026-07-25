#pragma once

#include "Tank.hpp"
#include <vector>
#include "./CollisionManager.hpp"
#include "Wall.hpp"

class Entity;
class Tank;
class Wall;
class PhysicsSystem final {
private:

public:
    void resolvePlayersWallsCollision(const std::vector<Tank*>& players, const std::vector<Wall*>& walls);
};