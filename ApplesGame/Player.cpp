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
}
