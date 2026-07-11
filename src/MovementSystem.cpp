#include "../include/MovementSystem.hpp"

MovementSystem::MovementSystem(std::vector<Entity*>& entities)
: entities(entities) {

}

void MovementSystem::update(const float& deltaTime) {
    for (auto entity: entities) {
        entity->update(deltaTime);
    }
}