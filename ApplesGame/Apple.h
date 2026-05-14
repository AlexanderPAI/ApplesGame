#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
	struct Apple
	{
		Position2D position;
		sf::Sprite sprite;
		float size = APPLE_SIZE;
	};

	struct Game;

	void InitApple(Apple& apple, float screenWidth, float screenHeigth, Game& game);
	void InitApples(Game& game);
	void RenderApple(Apple& apple, sf::RenderWindow& window);
	void RenderApples(Game& game, sf::RenderWindow& window);
}
