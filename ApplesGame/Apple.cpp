#include "Apple.h"

void InitApple(Apple& apple, float screenWidth, float screenHeigth)
{
	apple.position = GetRandomGameObjectPositionInScreen(screenWidth, screenWidth, "apple", apple.size);

	apple.shape.setRadius(apple.size / 2.f);
	apple.shape.setFillColor(sf::Color::Green);
	apple.shape.setOrigin(apple.size / 2.f, apple.size / 2.f);
	apple.shape.setPosition(apple.position.x, apple.position.y);
}
