#include "../include/Entity.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Angle.hpp>

Entity::Entity(sf::Texture& texture, sf::Vector2f startPosition)
: sprite(texture), position(startPosition), direction(0.f, 0.f), rotation(sf::degrees(0)) {

}
Entity::Entity(sf::Texture& texture, sf::Vector2f startPosition, sf::Angle startRotation)
: sprite(texture), position(startPosition), direction(0.f, 0.f), rotation(startRotation) {

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
void Entity::update(float deltaTime) {
    sprite.setPosition(position);
    sprite.setRotation(rotation);
}

void Entity::setPosition(sf::Vector2f newPosition) {
    previousPosition = position;
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
    previousRotation = rotation;
    rotation = newRotation;
}

sf::Angle Entity::getRotation() const {
    return rotation;
}

sf::FloatRect Entity::getLocalBounds() const {
    return sprite.getLocalBounds();
}
sf::Transform Entity::getTransform() const {
    return sprite.getTransform();
}

void Entity::undoPosition() {
    position = previousPosition;
}
void Entity::undoRotation() {
    rotation = previousRotation;
}

Entity::~Entity() = default;