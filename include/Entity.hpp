#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Transform.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
class Entity: public sf::Drawable {
protected:
    sf::Sprite sprite;
    float maxSpeed = 250;

    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Angle rotation;
    sf::Vector2f previousPosition;
    sf::Angle previousRotation;
public:
    Entity(sf::Texture& texture, sf::Vector2f startPosition);
    Entity(sf::Texture& texture, sf::Vector2f startPosition, sf::Angle startRotation);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update(float deltaTime);

    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition() const;

    void setDirection(sf::Vector2f newDirection);
    sf::Vector2f getDirection() const;

    void setRotation(sf::Angle newRotation);
    sf::Angle getRotation() const;

    sf::FloatRect getLocalBounds() const;
    sf::Transform getTransform() const;
    
    void undoPosition();
    void undoRotation();

    virtual ~Entity() = 0;
};