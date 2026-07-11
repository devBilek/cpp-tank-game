#pragma once

#include "Entity.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class Entity;
class RenderSystem final {
private:
    std::vector<Entity*>& entities;
    sf::RenderWindow& window;
public:
    RenderSystem(std::vector<Entity*>& entities, sf::RenderWindow& window);

    void update();
};