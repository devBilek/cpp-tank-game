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
    float maxSpeed = 250;

    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Angle rotation;


public:
    Entity(sf::Texture& texture, sf::Vector2f startPosition);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update(float deltaTime);

    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition() const;

    void setDirection(sf::Vector2f newDirection);
    sf::Vector2f getDirection() const;

    void setRotation(sf::Angle newRotation);
    sf::Angle getRotation() const;

    virtual ~Entity() = default;
};