#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
	struct Stone
	{
		Position2D position;
		sf::RectangleShape shape;
		sf::Sprite sprite;
		float size = STONE_SIZE;
	};

	struct Game;

	void InitStone(Stone& stone, float screenWidth, float screenHeight, Game& game);
	void RenderStone(Stone& stone, sf::RenderWindow& window);
}
