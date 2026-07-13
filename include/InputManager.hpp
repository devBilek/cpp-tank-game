#pragma once

#include <SFML/Window/Keyboard.hpp>

class InputManager final {
public:
    bool isKeyPressed(sf::Keyboard::Key key) const;
};