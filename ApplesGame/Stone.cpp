#include "Stone.h"
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

	void RenderStone(Stone& stone, sf::RenderWindow& window)
	{
		stone.sprite.setPosition(stone.position.x, stone.position.y);
		window.draw(stone.sprite);
	}
}
