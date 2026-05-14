#pragma once
#include "Constants.h"
#include "Game.h"
#include "UI.h"

namespace ApplesGame
{
	sf::Font InitFont()
	{
		sf::Font font;
		font.loadFromFile(RESOURCES_PATH + "\\Fonts\\arial.ttf");
		return font;
	}

	sf::Text InitLabel(sf::Font& font)
	{
		sf::Text scoreCounterLabel;
		scoreCounterLabel.setFont(font);
		scoreCounterLabel.setCharacterSize(14);
		scoreCounterLabel.setString("Scores: 0");
		scoreCounterLabel.setFillColor(sf::Color::White);
		scoreCounterLabel.setPosition(20, 20);
		return scoreCounterLabel;
	}

	void InitUI(Game& game)
	{
		game.numEatenApples = 0;
		game.font = InitFont();
		game.scoreCounterLabel = InitLabel(game.font);
	}

	struct Game;

	void IncreaseScoreCounter(Game& game)
	{
		++game.numEatenApples;
		game.scoreCounterLabel.setString("Scores: " + std::to_string(game.numEatenApples));
	}
}
