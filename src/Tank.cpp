#include "../include/Tank.hpp"
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <cmath>

Tank::Tank(sf::Texture& bodyTexture, sf::Texture& turretTexture, sf::Vector2f startPosition)
:Entity(bodyTexture, startPosition), turret(turretTexture) {
    sprite.setOrigin(sf::Vector2f(64.f, 64.f));
    turret.setOrigin(sf::Vector2f(64.f, 64.f));
};

void Tank::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Entity::draw(target, states);
    target.draw(turret, states);
}

void Tank::update(float deltaTime) {
    //body
    sf::Vector2f oldPosition = getPosition();
    sf::Vector2f newPosition(0, 0);

    if (direction != 0) {
        newPosition = sf::Vector2f(std::cos(rotation.asRadians()), std::sin(rotation.asRadians()));
    }
        
    setPosition(oldPosition + (direction * newPosition * deltaTime * maxSpeed));
    rotation += sf::degrees(rotationDirection) * deltaTime * 90;
    
    //turret
    turretRotation += sf::degrees(turretRotationDirection) * deltaTime * 90;
    
    //update
    Entity::update(deltaTime);
    turret.setPosition(position);
    turret.setRotation(rotation + turretRotation);
}

void Tank::setTurretRotationDirection(float newTurretDirection) {
    turretRotationDirection = newTurretDirection;
}
float Tank::getTurretRotationDirection() const {
    return turretRotationDirection;
}