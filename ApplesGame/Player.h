#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
	enum class PlayerDirection
	{
		Right = 0,
		Up,
		Left,
		Down
	};

	struct Player
	{
		Position2D position;
		float speed = INITIAL_SPEED;
		PlayerDirection direction = PlayerDirection::Right;
		sf::Sprite sprite;
	};


	// Forwart declaration (только ссылочные типы)
	struct Game;

	void InitPlayer(Player& player, Game& game);
	void RenderPlayer(Player& player, sf::RenderWindow& window);
	void IsKeyPressedToRotatePlayer(Player& player);
	void MovingPlayer(Player& player, float deltaTime);
}
