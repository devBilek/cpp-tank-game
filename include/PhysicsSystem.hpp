#pragma once

#include "BulletManager.hpp"
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
    void resolvePlayerBulletsCollision(const std::vector<Tank*>& players, BulletManager* bulletManager, int& player1points, int& player2points);
    void resolveBulletsWallCollision(BulletManager* bulletManager, const std::vector<Wall*>& walls);
};