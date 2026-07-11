#pragma once

#include "Entity.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Angle.hpp>
class Entity;

class Tank final: public Entity {
private:
    sf::Sprite turret;

    sf::Angle turretRotation;
    float turretRotationDirection;
public:
    Tank(sf::Texture& bodyTexture, sf::Texture& tankTexture, sf::Vector2f startPosition);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update(float deltaTime) override;

    void setTurretRotationDirection(float newTurretDirection);
    float getTurretRotationDirection() const;
};