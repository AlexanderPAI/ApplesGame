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
		sf::Text uiLabel;
		uiLabel.setFont(font);
		uiLabel.setCharacterSize(14);
		uiLabel.setString("Scores: 0");
		uiLabel.setFillColor(sf::Color::White);
		uiLabel.setPosition(20, 20);
		return uiLabel;
	}

	void InitUI(Game& game)
	{
		game.numEatenApples = 0;
		game.font = InitFont();
		game.uiLabel = InitLabel(game.font);
	}

	void ShowGameOverLabel(Game& game)
	{
		game.uiLabel.setString("GAME OVER");
		game.uiLabel.setFillColor(sf::Color::Red);
		game.uiLabel.setCharacterSize(50);

	}

	struct Game;

	void IncreaseScoreCounter(Game& game)
	{
		++game.numEatenApples;
		game.uiLabel.setString("Scores: " + std::to_string(game.numEatenApples));
	}
}
