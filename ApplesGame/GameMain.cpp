#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Apple.h"
#include "Constants.h"
#include "Game.h"

int main()
{
	using namespace ApplesGame;

	int seed = (int)time(nullptr);
	srand(seed);

	// Init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

	Game game;

	initGame(game);

	// Sync time
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	// Game Loop
	while (window.isOpen())
	{
		// Get deltaTime
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		// READ EVENTS
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// UPDATE GAME STATE
		updateGame(game, deltaTime);

		// RENDER GAME
		window.clear();
		renderGame(game, window);
		window.display();
	}

	// DEINITIALIZATION
	deinitializeGame(game);
	return 0;
}