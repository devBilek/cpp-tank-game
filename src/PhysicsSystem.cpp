#include "../include/PhysicsSystem.hpp"

void PhysicsSystem::resolvePlayersWallsCollision(const std::vector<Tank*>& players, const std::vector<Wall*>& walls) {
    for (const auto player: players) {
        for (const auto wall: walls) {
            if (CollisionManager::checkCollision(player, wall)) {
                player->undoPosition();
                player->undoRotation();
                break;
            }
        }   
    }
}

void PhysicsSystem::resolvePlayerBulletsCollision(const std::vector<Tank*>& players, BulletManager* bulletManager, int& player1points, int& player2points) {
    for (const auto player: players) {
        for (const auto& bullet: bulletManager->getBullets()) {
            if (CollisionManager::checkCollision(player, bullet.get()) && player->getID() != bullet->getOwnerID() && bullet->isActive()) {
                bullet->setActive(false);
                switch (bullet->getOwnerID()) {
                    case 1: player1points++; break;
                    case 2: player2points++; break;
                }
            }
        }
    }
}

void PhysicsSystem::resolveBulletsWallCollision(BulletManager* bulletManager, const std::vector<Wall*>& walls) {
    for (const auto& bullet: bulletManager->getBullets()) {
        for (const auto wall: walls) {
            if (CollisionManager::checkCollision(bullet.get(), wall)) {
                bullet->setActive(false);
            }
        }
    }
}