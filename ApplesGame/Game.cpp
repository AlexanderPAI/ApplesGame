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
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.stoneTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));

		// UI
		game.numEatenApples = 0;
		game.font = InitFont();
		game.scoreCounterLabel = InitUI(game.font);

		// Player
		InitPlayer(game.player, game);

		// Apples
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			InitApple(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT, game);
		}

		// Stones
		for (int i = 0; i < NUM_STONES; ++i)
		{
			InitStone(game.stones[i], SCREEN_WIDTH, SCREEN_HEIGHT, game);
		}
	}

	void updateGame(Game& game, float deltaTime)
	{
		if (!game.isPaused)
		{
			IsKeyPressedToRotatePlayer(game.player);
			MovingPlayer(game.player, deltaTime);

			IsEventEatApple(game);
			IsEventPlayerBorderCollition(game);


			// Stones collisions
			for (int i = 0; i < NUM_STONES; ++i)
			{
				if (IsRectangleCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE }, game.stones[i].position, { STONE_SIZE, STONE_SIZE }))
				{
					game.isGameOver = true;
				}
			}

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

		for (int i = 0; i < NUM_APPLES; ++i)
		{
			RenderApple(game.apples[i], window);
		}

		for (int i = 0; i < NUM_STONES; ++i)
		{
			RenderStone(game.stones[i], window);
		}
	}
}
