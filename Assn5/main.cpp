// Do not change any code in this file
#include "GGD.h"

int main()
{

	GGD game;
	// start game
	game.GameStart();
	while (!game.IsGameOver())
	{
		// do game until it is game over
		game.RoundProgress();
	}
	// print final game result
	game.PrintGameResult();

	return 0;
}