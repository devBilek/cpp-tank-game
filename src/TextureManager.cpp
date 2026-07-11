#include "../include/TextureManager.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <filesystem>
#include <stdexcept>

TextureManager& TextureManager::getInstance() {
    static TextureManager theInstance;
    return theInstance;
}

void TextureManager::addTexture(std::string textureName, std::string filePath) {
    if (textures.find(textureName) != textures.end()) {
        throw std::logic_error("TextureManager: Texture named " + textureName + " already loaded!");
    }

    if (!std::filesystem::exists(filePath)) {
        throw std::runtime_error("TextureManager: File not found " + filePath);
    }

    sf::Texture texture;
    if (!texture.loadFromFile(filePath)) {
        throw std::runtime_error("TextureManager: load from file error");
    }

    textures.emplace(textureName, texture);
}

sf::Texture& TextureManager::getTexture(std::string textureName) {
    if (textures.find(textureName) == textures.end()) {
        throw std::logic_error("TextureManager: Texture named " + textureName + " doesn't exist!");
    }
    
    return textures[textureName];
}