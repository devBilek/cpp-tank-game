#include "../include/InputManager.hpp"
#include "SFML/Window/Keyboard.hpp"

bool InputManager::isKeyPressed(sf::Keyboard::Key key) const {
    return sf::Keyboard::isKeyPressed(key);
}