#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

struct Stone
{
	Position2D position;
	sf::RectangleShape shape;
	float size = STONE_SIZE;
};

void InitStone(Stone& stone, float screenWidth, float screenHeight);
