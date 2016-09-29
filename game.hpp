#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <regex>
#include <algorithm>
#include <string>
#include "parser.hpp"
#include "player.hpp"
#include "Room/roomcreator.hpp"


class Game{
	Parser parser;
	Player player;
	RoomCreator * rooms = new RoomCreator(player);
	bool finished;

public:
	Game();
	~Game();
	void welcome();
	void start();
	void quit();
	bool processCommand(int);
};

#endif