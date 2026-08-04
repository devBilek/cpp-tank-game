#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <unordered_map>
#include <SFML/Graphics/RenderTexture.hpp>

class FontManager final {
private:
    std::unordered_map<std::string, sf::Font> fonts;

    FontManager() = default;
    FontManager(const FontManager&) = delete;
    FontManager(FontManager&&) = delete;
    FontManager& operator=(const FontManager&) = delete;
    FontManager& operator=(FontManager&&) = delete;

public:
    static FontManager& getInstance();

    void addFont(std::string FontName, std::string filePath);

    sf::Font& getFont(std::string FontName);
};