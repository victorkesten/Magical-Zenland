#ifndef TEST_H
#define TEST_H
#include "item.hpp"

class Test : public Item{


public:
	Test(double a, std::string nem, int easz){
		mWeight = a;
		mName = nem;
		itemID = easz;
	}
	Test(){}

	int getType() const override{
		return TEST;
	}
	void description() const override{
		std::cout << "Ahh you found the magical test item!" << std::endl;
	}
};

#endif