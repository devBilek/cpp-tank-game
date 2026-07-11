#include "../include/PlayerController.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/System/Angle.hpp>
//#include <cmath>

PlayerController::PlayerController(InputManager& inputManager, Tank* player)
:inputManager(inputManager), player(player) {

}

void PlayerController::update() {
    float newDirection = 0;
    float newRotationDirection = 0;
    float newTurretDirection = 0;

    if (inputManager.isKeyPressed(sf::Keyboard::Key::W)) {
        newDirection = 1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::A)) {
        newRotationDirection = -1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::S)) {
        newDirection = -1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::D)) {
        newRotationDirection = 1;
    }

    if (inputManager.isKeyPressed(sf::Keyboard::Key::T)) {
        newTurretDirection = -1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::Y)) {
        newTurretDirection = 1;
    }

    player->setDirection(newDirection);
    player->setRotationDirection(newRotationDirection);
    player->setTurretRotationDirection(newTurretDirection);
    
}