#pragma once

#include "InputManager.hpp"
#include "Tank.hpp"

class InputManager;
class Tank;
class PlayerController final {
private:
    InputManager& inputManager;
    Tank* player;
public:
    PlayerController(InputManager& inputManager, Tank* player);

    void update();
};