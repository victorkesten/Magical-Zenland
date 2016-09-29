#ifndef VICTORY_H
#define VICTORY_H
#include "room.hpp"

class Victory : public Room {
	std::string output = "FF";

public:
	Victory();
	~Victory(){actors.clear();};
	int temperature(int) override;
	std::string description() override;
	void changeDes(std::string) override;
	void lootDescription() override;
	bool unlockConditions() override;
};

#endif