#ifndef	MAIN_H
#define MAIN_H
#include "game.hpp"

int main(){
	
	Game * game = new Game();
	game->start();
	delete game;

	return 0;
}

#endif