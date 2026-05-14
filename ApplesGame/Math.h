#pragma once
#include <string>

// Forward declaration для sf
namespace sf
{
	class Sprite;
}


namespace ApplesGame
{
	struct Vector2D
	{
		float x = 0.f;
		float y = 0.f;
	};

	typedef Vector2D Position2D;


	Position2D GetRandomGameObjectPositionInScreen(float screenWidth, float screenHeight, std::string object, float objectSize);
	bool IsCircleCollide(Position2D object1Position, Vector2D object1Size, Position2D object2Position, Vector2D object2Size);
	bool IsRectangleCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size);
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
}
