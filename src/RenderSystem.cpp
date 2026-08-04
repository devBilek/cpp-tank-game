#include "../include/RenderSystem.hpp"

RenderSystem::RenderSystem(std::vector<Entity*>& entities, std::vector<GUIcomponent*>& guiComponents, BulletManager* bulletManager, sf::RenderWindow& window)
: entities(entities), guiComponents(guiComponents), bulletManager(bulletManager), window(window) {}

void RenderSystem::update() {
    for (const auto& entity: entities) {
        window.draw(*entity);
    }
    for (const auto& guiComponent: guiComponents) {
        window.draw(*guiComponent);
    }
    window.draw(*bulletManager);

}