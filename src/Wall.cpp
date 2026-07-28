#include "../include/Wall.hpp"
#include <SFML/Graphics/Rect.hpp>

Wall::Wall(sf::Texture& texture, sf::Vector2f startPosition, int width, int height): Entity(texture, startPosition), width(width), height(height) {
    sprite.setTextureRect(sf::IntRect({0,0}, {width, height}));
}