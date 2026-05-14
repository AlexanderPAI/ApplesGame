#include <SFML/Graphics.hpp>
#include "Apple.h"
#include "Constants.h"
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

	void InitApples(Game& game)
	{
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			InitApple(game.apples[i], SCREEN_WIDTH, SCREEN_HEIGHT, game);
		}
	}
	
	void RenderApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}

	void RenderApples(Game& game, sf::RenderWindow& window)
	{
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			RenderApple(game.apples[i], window);
		}
	}
}
