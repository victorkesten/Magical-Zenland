#ifndef GARDENS_H
#define GARDENS_H

#include "room.hpp"
#include <iostream>
class Gardens : public Room {
	std::string output = "GARDENS, GARDENS";

public: 
	Gardens();
	~Gardens(){actors.clear();};
	int temperature(int) override;
	std::string description() override;
	void changeDes(std::string) override;
	bool unlockConditions() override;
	void lootDescription() override;
};

#endif