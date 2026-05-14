#pragma once
#include <cassert>
#include "Game.h"
#include "Events.h"
#include "UI.h"

namespace ApplesGame
{
	void initGame(Game& game)
	{
		// GAME INITIALIZATION
		// Init game data
		game.isGameOver = false;
		game.pauseTime = 5.f;
		game.numEatenApples = 0;

		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Textures\\Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Textures\\Apple.png"));
		assert(game.stoneTexture.loadFromFile(RESOURCES_PATH + "\\Textures\\Rock.png"));

		InitUI(game);
		InitPlayer(game.player, game);
		InitApples(game);
		InitStones(game);

	}

	void updateGame(Game& game, float deltaTime)
	{
		if (!game.isPaused)
		{
			IsKeyPressedToRotatePlayer(game.player);
			MovingPlayer(game.player, deltaTime);

			IsEventEatApple(game);
			IsEventPlayerBorderCollition(game);
			IsEventPlayerStoneCollition(game);

			// Restart
			if (game.isGameOver)
			{
				restartGame(game);
			}
		}
		else
		{
			game.pauseTimeLeft -= deltaTime;
			if (game.pauseTimeLeft <= 0.f)
			{
				game.isPaused = false;
			}
		}
	}

	void deinitializeGame(Game& game)
	{

	}

	void restartGame(Game& game)
	{
		game.isPaused = true;
		game.pauseTimeLeft = game.pauseTime;

		initGame(game);
	}

	void renderGame(Game& game, sf::RenderWindow& window)
	{
		// Logic of drawing frame

		window.draw(game.scoreCounterLabel);

		RenderPlayer(game.player, window);
		RenderApples(game, window);
		RenderStones(game, window);
	}
}
