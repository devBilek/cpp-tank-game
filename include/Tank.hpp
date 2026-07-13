#pragma once

#include "Entity.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
class Entity;

class Tank final: public Entity {
private:
    sf::Vector2f rawInput;

    sf::Sprite turret;
    sf::Angle turretRotation;
    float turretRawInput;
    sf::Vector2f turretDirection;

    sf::Vector2f computeDirection();
    sf::Vector2f computeTurretDirection();
public:
    Tank(sf::Texture& bodyTexture, sf::Texture& tankTexture, sf::Vector2f startPosition);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update(float deltaTime) override;

    void setTurretRawInput(float newTurretRawInput);
    float getTurretRawInput() const;

    void setTurretRotation(sf::Angle newTurretRotation);
    sf::Angle getTurretRotation() const;

    void setRawInput(sf::Vector2f newRawInput);
    sf::Vector2f getRawInput() const;
    
    void setTurretDirection(sf::Vector2f newTurretDirection);
    sf::Vector2f getTurretDirection() const;
};