#include "../include/ScoreDisplay.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <string>

ScoreDisplay::ScoreDisplay(sf::Texture& texture, sf::Vector2f position, sf::Font& font, int& player1points, int& player2points)
:GUIcomponent(texture, position), player1points(player1points), player2points(player2points), scoreText(font) {
    scoreText.setFillColor(sf::Color::White);
    scoreText.setCharacterSize(24);
    scoreText.setString("0 : 0");

    sprite.setOrigin(sf::Vector2f(64.f, 32.f));

    updateScoreTextOrigin();
}

void ScoreDisplay::update() {
    GUIcomponent::update();
    scoreText.setString(std::to_string(player1points) + " : " + std::to_string(player2points));
    scoreText.setPosition(position);

}

void ScoreDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    GUIcomponent::draw(target, states);
    target.draw(scoreText, states);
}

void ScoreDisplay::updateScoreTextOrigin() {
    sf::FloatRect textBounds = scoreText.getLocalBounds();
    scoreText.setOrigin(sf::Vector2f(textBounds.position.x + textBounds.size.x / 2.f, textBounds.position.y + textBounds.size.y / 2.f));
    scoreText.setPosition(position);
}