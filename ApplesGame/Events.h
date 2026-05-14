#pragma once

namespace ApplesGame
{
	struct Game;

	void IsEventEatApple(Game& game);
	void IsEventPlayerBorderCollition(Game& game);
	void IsEventPlayerStoneCollition(Game& game);
	void IsEventGameOver(Game& game);
}