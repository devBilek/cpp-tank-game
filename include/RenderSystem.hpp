#pragma once

#include "Bullet.hpp"
#include "Entity.hpp"
#include "GUIcomponent.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class Entity;
class Bullet;
class GUIcomponent;
class RenderSystem final {
private:
    std::vector<Entity*>& entities;
    std::vector<GUIcomponent*>& guiComponents;
    sf::RenderWindow& window;
public:
    RenderSystem(std::vector<Entity*>& entities, std::vector<GUIcomponent*>& guiComponents, sf::RenderWindow& window);

    void update();
};