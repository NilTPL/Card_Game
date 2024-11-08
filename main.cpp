#include "stdafx.h"
#include "Game.h"
#include <iostream>


//using namespace sf;

int main()
{
	//Init srand
	std::srand(time(nullptr));

	//Init game
	Game game;


	//Game loop
	while (game.running())
	{
		//Update
		game.update();
		
		//Render
		game.render();
	};

	//End of application
	return 0;
}