#ifndef KEY_H
#define KEY_H
#include "item.hpp"

class Key : public Item{


public:
	Key(double a, std::string nem, int easz){
		mWeight = a;
		mName = nem;
		itemID = easz;
	}
	Key(){}

	int getType() const override{
		return KEY;
	}
	void description() const override{
		std::cout << "The key to the end!" << std::endl;
	}
};

#endif