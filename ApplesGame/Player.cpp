#include "Constants.h"
#include "Game.h"
#include "Math.h"
#include "Player.h"

namespace ApplesGame
{
	void InitPlayer(Player& player, const Game& game)
	{
		player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
		player.speed = INITIAL_SPEED;
		player.direction = PlayerDirection::Right;

		player.sprite.setTexture(game.playerTexture);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
	}

	void RenderPlayer(Player& player, sf::RenderWindow& window)
	{

		player.sprite.setPosition(player.position.x, player.position.y);
		window.draw(player.sprite);
	}

	void IsKeyPressedToRotatePlayer(Player& player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.direction = PlayerDirection::Right;
			player.sprite.setRotation(0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.direction = PlayerDirection::Up;
			player.sprite.setRotation(-90.f);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.direction = PlayerDirection::Left;
			player.sprite.setRotation(180.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.direction = PlayerDirection::Down;
			player.sprite.setRotation(90.f);
		}
	}

	void MovingPlayer(Player& player, float deltaTime)
	{
		switch (player.direction)
		{
		case PlayerDirection::Right:
		{
			player.position.x += player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			player.position.y -= player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			player.position.x -= player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			player.position.y += player.speed * deltaTime;
			break;
		}
		}
	}
}
