#include "../include/RenderSystem.hpp"

RenderSystem::RenderSystem(std::vector<Entity*>& entities, sf::RenderWindow& window)
: entities(entities), window(window) {}

void RenderSystem::update() {
    for (const auto& entity: entities) {
        window.draw(*entity);
    }
}