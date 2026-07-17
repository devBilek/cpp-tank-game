#include "../include/BulletManager.hpp"
#include <memory>

void BulletManager::fireBullet(sf::Vector2f startPosition, sf::Vector2f direction) {
    bullets.push_back(std::make_unique<Bullet>(TextureManager::getInstance().getTexture("bullet"), startPosition, direction));
}

const std::vector<std::unique_ptr<Bullet>>& BulletManager::getBullets() const {
    return bullets;
}

void BulletManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& bullet: bullets) {
        target.draw(*bullet, states);
    }
}
void BulletManager::update(float deltaTime) {
    for (const auto& bullet: bullets) {
        bullet->update(deltaTime);
    }
}