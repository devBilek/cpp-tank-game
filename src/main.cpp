#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
#include "../include/Entity.hpp"
#include "../include/RenderSystem.hpp"
#include "../include/TextureManager.hpp"
#include "../include/MovementSystem.hpp"
#include "../include/Tank.hpp"
#include "../include/InputManager.hpp"
#include "../include/PlayerController.hpp"
#include "../include/Bullet.hpp"
#include "../include/BulletManager.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 1200, 720 } ), "SFML works!" );
	sf::Clock clock;

	TextureManager& textureManager = TextureManager::getInstance();
	textureManager.addTexture("body", "body.png");
	textureManager.addTexture("turret", "turret.png");
	textureManager.addTexture("bullet", "bullet.png");

	std::vector<Entity*> entities;
	std::shared_ptr<Tank> ent = std::make_shared<Tank>(textureManager.getTexture("body"), textureManager.getTexture("turret"), sf::Vector2f(200, 200));
	entities.push_back(ent.get());
	std::shared_ptr<Bullet> bul = std::make_shared<Bullet>(textureManager.getTexture("bullet"), sf::Vector2f(200, 200), sf::Vector2f(1, 0));
	entities.push_back(bul.get());

	BulletManager bulletManager;

	RenderSystem renderSystem(entities, bulletManager.getBullets(), window);
	MovementSystem movementSystem(entities, bulletManager.getBullets());
	InputManager inputManager;
	PlayerController playerController(inputManager, ent.get(), bulletManager);
	

	while ( window.isOpen() )
	{
		sf::Time deltaTime = clock.restart();
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear(sf::Color(70, 70, 70));

		renderSystem.update();
		movementSystem.update(deltaTime.asSeconds());
		playerController.update();

		window.display();
	}
}
