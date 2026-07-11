#include "../include/Entity.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <SFML/System/Angle.hpp>

Entity::Entity(sf::Texture& texture, sf::Vector2f startPosition)
: sprite(texture), position(startPosition) {

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
void Entity::update(float deltaTime) {
    sprite.setPosition(position);
    sprite.setRotation(rotation);
}

void Entity::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

sf::Vector2f Entity::getPosition() const {
    return position;
}

void Entity::setDirection(float newDirection) {
    direction = newDirection;
}

float Entity::getDirection() const {
    return direction;
}

void Entity::setRotationDirection(float newRotationDirection) {
    rotationDirection = newRotationDirection;
}

float Entity::getRotationDirection() const {
    return rotationDirection;
}