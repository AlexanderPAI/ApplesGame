#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Apple.h"
#include "Constants.h"
#include "Math.h"
#include "Player.h"
#include "Stone.h"

namespace ApplesGame
{
	struct Game
	{
		Player player;
		Apple apples[NUM_APPLES];
		Stone stones[NUM_STONES];

		// Global game data
		bool isGameOver = false;
		bool isPaused = false;
		float pauseTime = 5.f;
		float pauseTimeLeft = 0.f;
		int numEatenApples = 0;

		// UI
		sf::Font font;
		sf::Text uiLabel;
		sf::Text gameOver;

		// Resources
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture stoneTexture;

		// Sounds
		sf::SoundBuffer appleEatSoundBuffer;
		sf::SoundBuffer deathSoundBuffer;
		sf::Sound appleEatSound;
		sf::Sound deathSound;
	};

	void initGame(Game& game);

	void updateGame(Game& game, float deltaTime);

	void deinitializeGame(Game& game);

	void restartGame(Game& game);

	void renderGame(Game& game, sf::RenderWindow& window);
}
