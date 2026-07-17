#pragma once

#include "BulletManager.hpp"
#include "InputManager.hpp"
#include "Tank.hpp"

class InputManager;
class Tank;
class BulletManager;
class PlayerController final {
private:
    InputManager& inputManager;
    Tank* player;
public:
    PlayerController(InputManager& inputManager, Tank* player);

    void update();
};