#include "../include/Tank.hpp"
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <cmath>
#include <iostream>

Tank::Tank(sf::Texture& bodyTexture, sf::Texture& turretTexture, sf::Vector2f startPosition)
:Entity(bodyTexture, startPosition), turret(turretTexture) {
    sprite.setOrigin(sf::Vector2f(64.f, 64.f));
    turret.setOrigin(sf::Vector2f(64.f, 64.f));
};

void Tank::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Entity::draw(target, states);
    target.draw(turret, states);
}

sf::Vector2f Tank::computeDirection() {
    return sf::Vector2f(std::cos(rotation.asRadians()), std::sin(rotation.asRadians()));
}
sf::Vector2f Tank::computeTurretDirection() {
    return sf::Vector2f(std::cos(turretRotation.asRadians()), std::sin(turretRotation.asRadians()));
}

void Tank::update(float deltaTime) {
    //body
    sf::Vector2f oldPosition = getPosition();
    if (rawInput.y != 0) {
        setPosition(oldPosition + (rawInput.y * direction * deltaTime * maxSpeed));

    }
    if (rawInput.x != 0) {
        setRotation(rotation + sf::degrees(rawInput.x * deltaTime * 90));

        setDirection(computeDirection());
    }
    
    //turret
    if (turretRawInput != 0) {
        setTurretRotation(turretRotation + sf::degrees(turretRawInput * deltaTime * 90));

        setTurretDirection(computeTurretDirection());
    }

    //update
    Entity::update(deltaTime);
    turret.setPosition(position);
    turret.setRotation(rotation + turretRotation);
}

void Tank::setTurretRawInput(float newTurretRawInput) {
    turretRawInput = newTurretRawInput;
}
float Tank::getTurretRawInput() const {
    return turretRawInput;
}

void Tank::setTurretRotation(sf::Angle newTurretRotation) {
    turretRotation = newTurretRotation;
}
sf::Angle Tank::getTurretRotation() const {
    return turretRotation;
}

void Tank::setRawInput(sf::Vector2f newRawInput) {
    rawInput = newRawInput;
}
sf::Vector2f Tank::getRawInput() const {
    return rawInput;
}

void Tank::setTurretDirection(sf::Vector2f newTurretDirection) {
    turretDirection = newTurretDirection;
}
sf::Vector2f Tank::getTurretDirection() const {
    return turretDirection;
}