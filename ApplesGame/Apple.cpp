#include "Apple.h"
#include "Game.h"
#include "Math.h"

namespace ApplesGame
{
	void InitApple(Apple& apple, float screenWidth, float screenHeigth, Game& game)
	{
		apple.position = GetRandomGameObjectPositionInScreen(screenWidth, screenWidth, "apple", apple.size);
		apple.sprite.setTexture(game.appleTexture);

		SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
	}
	void RenderApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}
}
