#include "Constants.h"
#include "Game.h"
#include "UI.h"
#include "Events.h"

namespace ApplesGame
{
	void IsEventEatApple(Game& game)
	{
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			if (IsCircleCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE }, game.apples[i].position, { APPLE_SIZE, APPLE_SIZE }))
			{
				InitApple(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT, game);
				IncreaseScoreCounter(game);
				game.player.speed += ACCELERATION;
			}
		}
	}

	void IsEventPlayerBorderCollition(Game& game)
	{
		if (game.player.position.x - PLAYER_SIZE / 2.f <= 0.f || game.player.position.x + PLAYER_SIZE / 2.f >= SCREEN_WIDTH || game.player.position.y - PLAYER_SIZE / 2.f <= 0.f || game.player.position.y + PLAYER_SIZE / 2.f >= SCREEN_HEIGHT)
		{
			game.isGameOver = true;
		}
	}
}
