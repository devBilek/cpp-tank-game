#include "../include/PhysicsSystem.hpp"
#include <iostream>

void PhysicsSystem::resolvePlayersWallsCollision(const std::vector<Tank*>& players, const std::vector<Wall*>& walls) {
    for (auto player: players) {
        for (auto wall: walls) {
            if (CollisionManager::checkCollision(player, wall)) {
                player->undoPosition();
                break;
            }
        }   
    }
}