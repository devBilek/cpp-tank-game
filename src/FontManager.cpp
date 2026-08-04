#include "../include/FontManager.hpp"

#include "SFML/Graphics/Font.hpp"
#include <filesystem>
#include <stdexcept>

FontManager& FontManager::getInstance() {
    static FontManager theInstance;
    return theInstance;
}

void FontManager::addFont(std::string fontName, std::string filePath) {
    if (fonts.find(fontName) != fonts.end()) {
        throw std::logic_error("FontManager: Font named " + fontName + " already loaded!");
    }

    if (!std::filesystem::exists(filePath)) {
        throw std::runtime_error("FontManager: File not found " + filePath);
    }

    sf::Font font;
    if (!font.openFromFile(filePath)) {
        throw std::runtime_error("FontManager: load from file error");
    }

    fonts.emplace(fontName, font);
}

sf::Font& FontManager::getFont(std::string fontName) {
    if (fonts.find(fontName) == fonts.end()) {
        throw std::logic_error("FontManager: Font named " + fontName + " doesn't exist!");
    }
    
    return fonts[fontName];
}
