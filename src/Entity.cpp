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

void Entity::setDirection(sf::Vector2f newDirection) {
    direction = newDirection;
}

sf::Vector2f Entity::getDirection() const {
    return direction;
}

void Entity::setRotation(sf::Angle newRotation) {
    rotation = newRotation;
}

sf::Angle Entity::getRotation() const {
    return rotation;
}