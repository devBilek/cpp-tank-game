#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class GUIcomponent: public sf::Drawable {
protected:
    sf::Sprite sprite;
    sf::Vector2f position;

public:
    GUIcomponent(sf::Texture& texture, sf::Vector2f position);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update();

    virtual ~GUIcomponent() = 0;
};