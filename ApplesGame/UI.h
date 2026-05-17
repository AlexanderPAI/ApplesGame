#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	sf::Font InitFont();
	sf::Text InitLabel(sf::Font& font);
	void InitUI(Game& game);
	void ShowGameOverLabel(Game& game);
	void ShowPauseLabel(Game& game);

	struct Game;

	void IncreaseScoreCounter(Game& game);
}
