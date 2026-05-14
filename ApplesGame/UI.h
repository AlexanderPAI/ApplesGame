#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	sf::Font InitFont();
	sf::Text InitUI(sf::Font& font);

	struct Game;

	void IncreaseScoreCounter(Game& game);
}
