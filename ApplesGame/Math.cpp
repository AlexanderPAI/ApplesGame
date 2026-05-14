#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
	Position2D GetRandomGameObjectPositionInScreen(float screenWidth, float screenHeight, std::string object, float objectSize)
	{
		Position2D result;

		if (object == "apple" || object == "stone")
		{
			float halfSize = objectSize / 2.f;
			result.x = rand() / (float)RAND_MAX * (screenWidth - 2 * halfSize) + halfSize;
			result.y = rand() / (float)RAND_MAX * (screenHeight - 2 * halfSize) + halfSize;
			return result;
		}
		else
		{
			return result;
		}
	}

	bool IsCircleCollide(Position2D object1Position, Vector2D object1Size, Position2D object2Position, Vector2D object2Size)
	{
		float sqrDistanse = (object1Position.x - object2Position.x) * (object1Position.x - object2Position.x) + (object1Position.y - object2Position.y) * (object1Position.y - object2Position.y);
		float sqrRadiusSum = (object1Size.x + object2Size.x) * (object1Size.y + object2Size.y) / 4;
		return (sqrDistanse <= sqrRadiusSum);
	}

	bool IsRectangleCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size)
	{
		float deltaPosX = (float)fabs(rect1Position.x - rect2Position.x);
		float deltaPosY = (float)fabs(rect1Position.y - rect2Position.y);

		return (deltaPosX <= (rect1Size.x + rect2Size.x) / 2.f && deltaPosY <= (rect1Size.y + rect1Size.y) / 2.f);
	}

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredHeight / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}
