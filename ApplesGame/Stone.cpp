#include "Stone.h"

namespace ApplesGame
{
	void InitStone(Stone& stone, float screenWidth, float screenHeight)
	{
		stone.position = GetRandomGameObjectPositionInScreen(screenWidth, screenHeight, "stone", stone.size);

		stone.shape.setSize(sf::Vector2f(stone.size, stone.size));
		stone.shape.setFillColor(sf::Color::White);
		stone.shape.setOrigin(stone.size / 2.f, stone.size / 2.f);
		stone.shape.setPosition(stone.position.x, stone.position.y);
	}
}
