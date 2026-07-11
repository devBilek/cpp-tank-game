#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
class InputManager final {
private:
    std::unordered_map<sf::Keyboard::Key, bool> isKeyDown;
public:
    bool isKeyPressed(sf::Keyboard::Key key) const;
};