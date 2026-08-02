#include "../include/PlayerController.hpp"
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
//#include <cmath>

PlayerController::PlayerController(InputManager& inputManager, Tank* player, ControlBindings controlBindings)
:inputManager(inputManager), player(player), controlBindings(controlBindings) {

}

void PlayerController::update() {
    sf::Vector2f newRawInput(0.f, 0.f);
    float newTurretRawInput = 0;

    //body
    if (inputManager.isKeyPressed(controlBindings.up)) {
        newRawInput.y = 1;
    }
    if (inputManager.isKeyPressed(controlBindings.left)) {
        newRawInput.x = -1;
    }
    if (inputManager.isKeyPressed(controlBindings.down)) {
        newRawInput.y = -1;
    }
    if (inputManager.isKeyPressed(controlBindings.right)) {
        newRawInput.x = 1;
    }

    //turret
    if (inputManager.isKeyPressed(controlBindings.turretLeft)) {
        newTurretRawInput = -1;
    }
    if (inputManager.isKeyPressed(controlBindings.turretRight)) {
        newTurretRawInput = 1;
    }

    //actions
    if (inputManager.isKeyPressed(controlBindings.shoot)) {
        player->fireBullet();
    }

    player->setRawInput(newRawInput);
    player->setTurretRawInput(newTurretRawInput);
    
}