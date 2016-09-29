#ifndef CIVILLIAN_H
#define CIVILLIAN_H
#include "human.hpp"

#include <iostream>
#include "../player.hpp"
#include "../Item/health.hpp"

class Civillian : public Human {
	Player * player;
	bool hasItem;
	Health * health = new Health();
public: 
	Civillian(int a, std::string name_p, Player & p){
		name = name_p;
		hasItem = true;
		player = &p;
		
		health->setName("HealthUpgrade");
		health->setID(4);
		health->setWeight(5.0);
	};
	virtual ~Civillian(){delete health;};

	void giveItem(){
		//give item
		player->setHealth(75);
		player->addItem(*health);
		std::cout << "This should help you on your journey!" << std::endl;
		std::cout << "[Your total health has increased from 50 to 75]" << std::endl;
	}

	int getType() const{
		return CIVILLIAN;
	};
	bool action(){
		std::cout << "Oh hello there! How are you? I'm " << name << "." << std::endl;
		if(hasItem){
			std::cout << "You look like you're going into the forest! Talk to me and I can hook you up with some gear." << std::endl;
			//giveItem();
			//hasItem = false;
		}  else {
			laugh();
		}
		return false;
	};

	std::string interact(){
		if (hasItem){
			giveItem();
			hasItem = false;
		} else {
			std::cout << "Sorry! I have no more items for you. Good luck in your journey!" << std::endl;
		}
		return "I heard rumors of something grand in the forest. Beware!";
	};
};

#endif