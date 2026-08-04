#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
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
#include "../include/Wall.hpp"
#include "../include/PhysicsSystem.hpp"
#include "../include/ControlBindings.hpp"
#include "../include/FontManager.hpp"
#include "../include/GUIcomponent.hpp"
#include "../include/ScoreDisplay.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 1200, 720 } ), "SFML works!" );
	sf::Clock clock;

	TextureManager& textureManager = TextureManager::getInstance();
	textureManager.addTexture("body", "body.png");
	textureManager.addTexture("turret", "turret.png");
	textureManager.addTexture("bullet", "bullet.png");
	textureManager.addTexture("wall", "wall.png");
	textureManager.setTextureRepeated("wall", true);
	textureManager.addTexture("scoreDisplay", "scoreDisplay.png");

	FontManager& fontManager = FontManager::getInstance();
	fontManager.addFont("font1", "arial.ttf");

	std::vector<Entity*> entities;
	std::shared_ptr<Tank> ent = std::make_shared<Tank>(textureManager.getTexture("body"), textureManager.getTexture("turret"), sf::Vector2f(200, 200));
	std::shared_ptr<Tank> ent1 = std::make_shared<Tank>(textureManager.getTexture("body"), textureManager.getTexture("turret"), sf::Vector2f(1100, 500), sf::degrees(180));
	std::shared_ptr<Wall> wall1 = std::make_shared<Wall>(textureManager.getTexture("wall"), sf::Vector2f(300.f, 120.f), 64, 256);
	std::shared_ptr<Wall> wall2 = std::make_shared<Wall>(textureManager.getTexture("wall"), sf::Vector2f(900.f, 390.f), 64, 256);
	std::shared_ptr<Wall> wall3 = std::make_shared<Wall>(textureManager.getTexture("wall"), sf::Vector2f(600.f, 200.f), 128, 64);
	entities.push_back(ent.get());
	entities.push_back(ent1.get());
	entities.push_back(wall1.get());
	entities.push_back(wall2.get());
	entities.push_back(wall3.get());

	std::vector<Tank*> players;
	players.push_back(ent.get());
	players.push_back(ent1.get());
	std::vector<Wall*> walls;
	walls.push_back(wall1.get());
	walls.push_back(wall2.get());
	walls.push_back(wall3.get());
	int player1points = 0, player2points = 0;
	std::vector<GUIcomponent*> guiComponents;
	std::shared_ptr<ScoreDisplay> scoreDisplay = std::make_shared<ScoreDisplay>(textureManager.getTexture("scoreDisplay"), sf::Vector2f(600.f, 690.f), fontManager.getFont("font1"), player1points, player2points);
	guiComponents.push_back(scoreDisplay.get());

	ControlBindings Player1ControlBindings {
		sf::Keyboard::Key::W,
		sf::Keyboard::Key::A,
		sf::Keyboard::Key::S,
		sf::Keyboard::Key::D,
		sf::Keyboard::Key::T,
		sf::Keyboard::Key::Y,
		sf::Keyboard::Key::U
	};
	ControlBindings Player2ControlBindings {
		sf::Keyboard::Key::Up,
		sf::Keyboard::Key::Left,
		sf::Keyboard::Key::Down,
		sf::Keyboard::Key::Right,
		sf::Keyboard::Key::Numpad1,
		sf::Keyboard::Key::Numpad2,
		sf::Keyboard::Key::Numpad3
	};
	RenderSystem renderSystem(entities, guiComponents, window);
	MovementSystem movementSystem(entities);
	InputManager inputManager;
	PlayerController player1Controller(inputManager, ent.get(), Player1ControlBindings);
	PlayerController player2Controller(inputManager, ent1.get(), Player2ControlBindings);
	PhysicsSystem physicsSystem;
	

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
		player1Controller.update();
		player2Controller.update();
		scoreDisplay->update();

		physicsSystem.resolvePlayersWallsCollision(players, walls);

		window.display();
	}
}
