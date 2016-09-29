#ifndef FOREST_H
#define FOREST_H
#include "room.hpp"

class Forest : public Room {
	std::string output = "FF";

public:
	Forest();
	~Forest(){actors.clear();};
	int temperature(int pH) override;
	std::string description() override;
	void changeDes(std::string) override;
	void lootDescription() override;
	bool unlockConditions() override;
};

#endif