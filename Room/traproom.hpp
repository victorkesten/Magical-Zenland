#ifndef TRAPROOM_H
#define TRAPROOM_H
#include "room.hpp"

class Traproom : public Room {
	std::string output = "FF";
	bool turn = false;
	int count = 2;

public:
	Traproom();
	~Traproom(){actors.clear();};

	int temperature(int) override;
	std::string description() override;
	void changeDes(std::string) override;
	void lootDescription() override;
	bool unlockConditions() override;
};

#endif