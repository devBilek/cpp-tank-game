#include "../include/MovementSystem.hpp"

MovementSystem::MovementSystem(std::vector<Entity*>& entities, std::vector<std::unique_ptr<Bullet>>& bullets)
: entities(entities), bullets(bullets) {

}

void MovementSystem::update(const float& deltaTime) {
    for (const auto& entity: entities) {
        entity->update(deltaTime);
    }
    for (const auto& bullet: bullets) {
        bullet->update(deltaTime);
    }
}