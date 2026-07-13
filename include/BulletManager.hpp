#pragma once

#include "Bullet.hpp"
#include "TextureManager.hpp"
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

class TextureManager;
class Bullet;
class BulletManager final {
private:
    std::vector<std::unique_ptr<Bullet>> bullets;
    
public:
    BulletManager() = default;
    void fireBullet(sf::Vector2f startPosition, sf::Vector2f direction);

    std::vector<std::unique_ptr<Bullet>>& getBullets();
};