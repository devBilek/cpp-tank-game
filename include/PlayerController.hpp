#pragma once

#include "ControlBindings.hpp"
#include "InputManager.hpp"
#include "Tank.hpp"

class InputManager;
class Tank;
class BulletManager;
struct ControlBindings;
class PlayerController final {
private:
    InputManager& inputManager;
    Tank* player;
    ControlBindings controlBindings;
public:
    PlayerController(InputManager& inputManager, Tank* player, ControlBindings controlBindings);

    void update();
};