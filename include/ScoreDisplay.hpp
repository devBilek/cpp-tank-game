#pragma once

#include "GUIcomponent.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class GUIcomponent;
class ScoreDisplay final: public GUIcomponent {
private:
    int& player1points;
    int& player2points;

    sf::Text scoreText;

    void updateScoreTextOrigin();
public:
    ScoreDisplay(sf::Texture& texture, sf::Vector2f position, sf::Font& font, int& player1points, int& player2points);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update() override;

};