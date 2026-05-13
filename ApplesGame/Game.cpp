#pragma once
#include "Game.h"
#include "UI.h"

void initGame(Game& game)
{
	// GAME INITIALIZATION
	// Init game data
	game.isGameOver = false;
	game.pauseTime = 5.f;
	game.numEatenApples = 0;

	// UI
	game.numEatenApples = 0;
	game.font = InitFont();
	game.scoreCounterLabel = InitUI(game.font);

	// Player
	InitPlayer(game.player);

	// Apples
	for (int i = 0; i < NUM_APPLES; ++i)
	{
		InitApple(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	// Stones
	for (int i = 0; i < NUM_STONES; ++i)
	{
		InitStone(game.stones[i], SCREEN_WIDTH, SCREEN_HEIGHT);
	}
}

void updateGame(Game& game, float deltaTime)
{
	if (!game.isPaused)
	{
		// Check press keyboard key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			game.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			game.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			game.player.direction = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			game.player.direction = PlayerDirection::Down;
		}

		// Update player acceleration
		//playerSpeed += ACCELERATION * deltaTime;

		// Player moving
		switch (game.player.direction)
		{
		case PlayerDirection::Right:
		{
			game.player.position.x += game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			game.player.position.y -= game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			game.player.position.x -= game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			game.player.position.y += game.player.speed * deltaTime;
			break;
		}
		}

		// Logic of eating apples
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			if (IsCircleCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE }, game.apples[i].position, { APPLE_SIZE, APPLE_SIZE }))
			{
				InitApple(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT);

				++game.numEatenApples;
				game.scoreCounterLabel.setString("Scores: " + std::to_string(game.numEatenApples));
				game.player.speed += ACCELERATION;
			}
		}

		// Check GameEnd Conditions
		// Borders collisions
		if (game.player.position.x - PLAYER_SIZE / 2.f <= 0.f || game.player.position.x + PLAYER_SIZE / 2.f >= SCREEN_WIDTH || game.player.position.y - PLAYER_SIZE / 2.f <= 0.f || game.player.position.y + PLAYER_SIZE / 2.f >= SCREEN_HEIGHT)
		{
			game.isGameOver = true;
		}

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

	game.player.shape.setPosition(game.player.position.x, game.player.position.y);
	window.draw(game.player.shape);

	for (int i = 0; i < NUM_APPLES; ++i)
	{
		window.draw(game.apples[i].shape);
	}

	for (int i = 0; i < NUM_STONES; ++i)
	{
		window.draw(game.stones[i].shape);
	}
}
