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
    std::vector<std::unique_ptr<Bullet>>& bullets;
    sf::RenderWindow& window;
public:
    RenderSystem(std::vector<Entity*>& entities, std::vector<std::unique_ptr<Bullet>>& bullets, sf::RenderWindow& window);

    void update();
};