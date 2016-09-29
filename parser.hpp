#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <regex>
#include "commands.hpp"

class Parser{
	Commands commands;
	std::string strVec[3];
	std::string playerName;

	public:
		enum {
			GO_C,
			PICKUP_C,
			EXAMINE_C,
			QUIT_C,
			COMMANDS_C,
			DIRECTION_C,
			BACKPACK_C,
			WHEREAMI_C,
			WHOAMI_C,
			TALK_C,
			HEALTH_C
		};

		Parser();
		int parse();
		int translate(std::string) const;
		std::string * split(std::string str);
		std::string getSecondWord() const;
		std::string getThirdWord() const;
};

#endif