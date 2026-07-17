#pragma once

#include "Bullet.hpp"
#include "TextureManager.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

class TextureManager;
class Bullet;
class BulletManager final: sf::Drawable {
private:
    std::vector<std::unique_ptr<Bullet>> bullets;
    
public:
    BulletManager() = default;
    void fireBullet(sf::Vector2f startPosition, sf::Vector2f direction);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(float deltaTime);

    const std::vector<std::unique_ptr<Bullet>>& getBullets() const;
};