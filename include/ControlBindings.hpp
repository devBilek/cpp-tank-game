#pragma once

#include <SFML/Window/Keyboard.hpp>
struct ControlBindings {
    //body
    sf::Keyboard::Key up;
    sf::Keyboard::Key left;
    sf::Keyboard::Key down;
    sf::Keyboard::Key right;

    //turret
    sf::Keyboard::Key turretLeft;
    sf::Keyboard::Key turretRight;

    //actions
    sf::Keyboard::Key shoot;

};