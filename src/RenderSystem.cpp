#include "../include/RenderSystem.hpp"

RenderSystem::RenderSystem(std::vector<Entity*>& entities, std::vector<std::unique_ptr<Bullet>>& bullets, sf::RenderWindow& window)
: entities(entities), bullets(bullets), window(window) {}

void RenderSystem::update() {
    for (const auto& entity: entities) {
        window.draw(*entity);
    }
    for (const auto& bullet: bullets) {
        window.draw(*bullet);
    }
}