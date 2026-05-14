#pragma once
#include "Game.h"
#include "UI.h"

namespace ApplesGame
{
	sf::Font InitFont()
	{
		sf::Font font;
		font.loadFromFile("arial.ttf");
		return font;
	}

	sf::Text InitUI(sf::Font& font)
	{
		sf::Text scoreCounterLabel;
		scoreCounterLabel.setFont(font);
		scoreCounterLabel.setCharacterSize(14);
		scoreCounterLabel.setString("Scores: 0");
		scoreCounterLabel.setFillColor(sf::Color::White);
		scoreCounterLabel.setPosition(20, 20);
		return scoreCounterLabel;
	}

	struct Game;

	void IncreaseScoreCounter(Game& game)
	{
		++game.numEatenApples;
		game.scoreCounterLabel.setString("Scores: " + std::to_string(game.numEatenApples));
	}
}
