#include "../include/GUIcomponent.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/RenderTexture.hpp>

GUIcomponent::GUIcomponent(sf::Texture& texture, sf::Vector2f position)
: sprite(texture), position(position) {

}

void GUIcomponent::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void GUIcomponent::update() {
    sprite.setPosition(position);
}

GUIcomponent::~GUIcomponent() = default;
