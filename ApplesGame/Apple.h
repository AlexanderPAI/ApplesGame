#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

struct Apple
{
	Position2D position;
	sf::CircleShape shape;
	float size = APPLE_SIZE;
};

void InitApple(Apple& apple, float screenWidth, float screenHeigth);
