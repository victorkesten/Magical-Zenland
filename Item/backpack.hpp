#ifndef BACKPACK_H
#define BACKPACK_H
#include "item.hpp"
#include <iostream>

class Backpack : public Item{
	double maxWeight;
	//Item backpack[20];
	Item * backpack[20];
	//Item * bp[20];
	int slot;
	double currentWeight = 0.0;
	public: 
		Backpack();
		Backpack(double);
		~Backpack(){
			for(int i = 0; i < 20; i++){
				backpack[i] = nullptr;
			}
		};

		//bool addItem(Item *);
		bool addItem(Item &);
		bool removeItem(Item *);
		double returnWeight() const;
		double returnMaxWeight() const;
		void description() const override;
		void setWeight(int );

		int getType() const override {
			return BACKPACK;
		}

		std::string returnContent();
};

#endif