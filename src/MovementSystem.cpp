#include "../include/MovementSystem.hpp"

MovementSystem::MovementSystem(std::vector<Entity*>& entities, BulletManager* bulletManager)
: entities(entities), bulletManager(bulletManager) {

}

void MovementSystem::update(const float& deltaTime) {
    for (const auto& entity: entities) {
        if (entity->isActive()) {
            entity->update(deltaTime);
        }
    }
    bulletManager->update(deltaTime);
}