#pragma once

#include "SFML/Graphics/Texture.hpp"
#include <string>
#include <unordered_map>
class TextureManager final {
private:
    std::unordered_map<std::string, sf::Texture> textures;

    TextureManager() = default;
    TextureManager(const TextureManager&) = delete;
    TextureManager(TextureManager&&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;
    TextureManager& operator=(TextureManager&&) = delete;

public:
    static TextureManager& getInstance();

    void addTexture(std::string textureName, std::string filePath);

    sf::Texture& getTexture(std::string textureName);
};