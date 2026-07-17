#include "../include/PlayerController.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
//#include <cmath>

PlayerController::PlayerController(InputManager& inputManager, Tank* player)
:inputManager(inputManager), player(player) {

}

void PlayerController::update() {
    sf::Vector2f newRawInput(0.f, 0.f);
    float newTurretRawInput = 0;

    if (inputManager.isKeyPressed(sf::Keyboard::Key::W)) {
        newRawInput.y = 1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::A)) {
        newRawInput.x = -1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::S)) {
        newRawInput.y = -1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::D)) {
        newRawInput.x = 1;
    }

    if (inputManager.isKeyPressed(sf::Keyboard::Key::T)) {
        newTurretRawInput = -1;
    }
    if (inputManager.isKeyPressed(sf::Keyboard::Key::Y)) {
        newTurretRawInput = 1;
    }



    if (inputManager.isKeyPressed(sf::Keyboard::Key::U)) {
        //sf::Vector2f newDir = sf::Vector2f(std::cos(player->getRotation().asRadians() + player->getTurretRotation().asRadians()), std::sin(player->getRotation().asRadians() + player->getTurretRotation().asRadians()));
        //player
        player->fireBullet();
    }

    player->setRawInput(newRawInput);
    player->setTurretRawInput(newTurretRawInput);
    
}