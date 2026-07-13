#pragma once 

#include "Entity.hpp"
#include <SFML/System/Vector2.hpp>

class Entity;
class Bullet final: public Entity {
private:

public:
    Bullet(sf::Texture& texture, sf::Vector2f startPosition, sf::Vector2f startDirection);
    virtual void update(float deltaTime) override;
};