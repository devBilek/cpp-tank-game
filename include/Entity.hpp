#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
class Entity: public sf::Drawable {
protected:
    sf::Sprite sprite;
    const float maxSpeed = 250;

    sf::Vector2f position;
    float direction;

    sf::Angle rotation;
    float rotationDirection;


public:
    Entity(sf::Texture& texture, sf::Vector2f startPosition);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update(float deltaTime);

    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition() const;

    void setDirection(float newDirection);
    float getDirection() const;

    void setRotationDirection(float newRotationDirection);
    float getRotationDirection() const;

    virtual ~Entity() = default;
};