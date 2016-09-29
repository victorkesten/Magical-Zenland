#ifndef HEALTH_H
#define HEALTH_H
#include "item.hpp"

class Health : public Item{


public:
	Health(double a, std::string nem, int easz){
		mWeight = a;
		mName = nem;
		itemID = easz;
	}
	Health(){}

	int getType() const override{
		return HEALTH;
	}
	void description() const override{
		std::cout << "The HEALTH to the end!" << std::endl;
	}
};

#endif