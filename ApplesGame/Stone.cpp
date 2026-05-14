#include "Stone.h"
#include "Constants.h"
#include "Game.h"
#include "Math.h"

namespace ApplesGame
{
	void InitStone(Stone& stone, float screenWidth, float screenHeight, Game& game)
	{
		stone.position = GetRandomGameObjectPositionInScreen(screenWidth, screenHeight, "stone", stone.size);
		stone.sprite.setTexture(game.stoneTexture);

		SetSpriteSize(stone.sprite, STONE_SIZE, STONE_SIZE);
		SetSpriteRelativeOrigin(stone.sprite, 0.5f, 0.5f);
	}

	void InitStones(Game& game)
	{
		for (int i = 0; i < NUM_STONES; ++i)
		{
			InitStone(game.stones[i], SCREEN_WIDTH, SCREEN_HEIGHT, game);
		}
	}

	void RenderStone(Stone& stone, sf::RenderWindow& window)
	{
		stone.sprite.setPosition(stone.position.x, stone.position.y);
		window.draw(stone.sprite);
	}

	void RenderStones(Game& game, sf::RenderWindow& window)
	{
		for (int i = 0; i < NUM_STONES; ++i)
		{
			RenderStone(game.stones[i], window);
		}
	}
}
