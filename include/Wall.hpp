#pragma once

#include "Entity.hpp"
class Entity;

class Wall final: public Entity {
private:
    int width = 128;
    int height = 256;
public:
    Wall(sf::Texture& texture, sf::Vector2f startPosition);
};