#pragma once

#include "Bullet.hpp"
#include "Entity.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

class Entity;
class Bullet;
class RenderSystem final {
private:
    std::vector<Entity*>& entities;
    sf::RenderWindow& window;
public:
    RenderSystem(std::vector<Entity*>& entities, sf::RenderWindow& window);

    void update();
};