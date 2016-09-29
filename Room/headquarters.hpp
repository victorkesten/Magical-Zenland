#ifndef HQ_H
#define HQ_H
#include "room.hpp"
#include <iostream>
class Headquarters : public Room {
	std::string output = "HQ, HQ";

public: 
	Headquarters();
	~Headquarters(){actors.clear();};
	int temperature(int pH) override;
	std::string description() override;
	void changeDes(std::string) override;
	bool unlockConditions() override;
	void lootDescription() override;


};

#endif