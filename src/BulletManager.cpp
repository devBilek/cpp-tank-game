#include "../include/BulletManager.hpp"
#include <memory>

void BulletManager::fireBullet(sf::Vector2f startPosition, sf::Vector2f direction) {
    bullets.push_back(std::make_unique<Bullet>(TextureManager::getInstance().getTexture("bullet"), startPosition, direction));
}

std::vector<std::unique_ptr<Bullet>>& BulletManager::getBullets() {
    return bullets;
}