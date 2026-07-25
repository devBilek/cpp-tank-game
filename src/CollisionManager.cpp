//made by ai
#include "../include/CollisionManager.hpp"
#include <vector>

bool CollisionManager::checkCollision(const Entity* entity1, const Entity* entity2) {
    if (!entity1 || !entity2) return false;

    // Pobieranie czterech wierzchołków sprite'a w przestrzeni świata
    auto getWorldCorners = [](const Entity* entity) -> std::array<sf::Vector2f, 4> {
        sf::FloatRect bounds = entity->getLocalBounds();
        sf::Transform transform = entity->getTransform();
        return {
            transform.transformPoint({bounds.position.x, bounds.position.y}),
            transform.transformPoint({bounds.position.x + bounds.size.x, bounds.position.y}),
            transform.transformPoint({bounds.position.x + bounds.size.x, bounds.position.y + bounds.size.y}),
            transform.transformPoint({bounds.position.x, bounds.position.y + bounds.size.y})
        };
    };

    std::array<sf::Vector2f, 4> poly1 = getWorldCorners(entity1);
    std::array<sf::Vector2f, 4> poly2 = getWorldCorners(entity2);

    // Rzutowanie wielokąta na oś
    auto project = [](const std::array<sf::Vector2f, 4>& polygon, const sf::Vector2f& axis,
                       float& min, float& max) {
        min = std::numeric_limits<float>::max();
        max = std::numeric_limits<float>::lowest();
        for (const auto& point : polygon) {
            float projection = point.x * axis.x + point.y * axis.y;
            if (projection < min) min = projection;
            if (projection > max) max = projection;
        }
    };

    // Dodawanie osi (normalnych do krawędzi) z wielokąta
    auto addAxes = [](const std::array<sf::Vector2f, 4>& polygon,
                      std::vector<sf::Vector2f>& axes) {
        for (size_t i = 0; i < 4; ++i) {
            sf::Vector2f edge = polygon[(i + 1) % 4] - polygon[i];
            sf::Vector2f normal = {edge.y, -edge.x};
            float length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
            if (length > 0.0f) {
                normal /= length;
                axes.push_back(normal);
            }
        }
    };

    std::vector<sf::Vector2f> axes;
    addAxes(poly1, axes);
    addAxes(poly2, axes);

    // Test SAT na wszystkich osiach
    for (const auto& axis : axes) {
        float min1, max1, min2, max2;
        project(poly1, axis, min1, max1);
        project(poly2, axis, min2, max2);

        if (max1 < min2 || max2 < min1) {
            return false; // brak kolizji
        }
    }

    return true; // kolizja
}