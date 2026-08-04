#pragma once 

#include "Entity.hpp"
#include <SFML/System/Vector2.hpp>

class Entity;
class Bullet final: public Entity {
private:
    int tankID;
public:
    Bullet(sf::Texture& texture, sf::Vector2f startPosition, sf::Vector2f startDirection, int tankID);
    virtual void update(float deltaTime) override;
    int getOwnerID() const;
};