#include "../include/Bullet.hpp"
#include "SFML/System/Vector2.hpp"

Bullet::Bullet(sf::Texture& texture, sf::Vector2f startPosition, sf::Vector2f startDirection)
: Entity(texture, startPosition) {
    direction = startDirection;
    maxSpeed = 700;
    sprite.setOrigin(sf::Vector2f(8.f, 8.f));
}

void Bullet::update(float deltaTime) {
    sf::Vector2f oldPosition = getPosition();
    sf::Vector2f newPosition(0.f, 0.f);

    newPosition = oldPosition + (direction * maxSpeed * deltaTime);

    setPosition(newPosition);
    Entity::update(deltaTime);
}