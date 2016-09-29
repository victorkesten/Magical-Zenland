#ifndef WIZARD_H
#define WIZARD_H

#include "human.hpp"
#include <iostream>
#include "../player.hpp"

class Wizard : public Human {
	Player * player;
public: 
	Wizard(int a, std::string name_p, Player & p){
		name = name_p;
		player = &p;
	};
	~Wizard(){};

	void castHealingSpell(){
		if(player->hasUpgrade()){
			player->setHealth(75);
		} else {
			player->setHealth(50);
		}
		std::cout << name <<" heals you to full health! Your current health is " << player->getHealth() << "." << std::endl;
	}

	int getType() const{
		return WIZARD;
	};
	bool action(){
		std::cout << "Greetings traveler! I am the friendly wizard, " << name << ". How are you today?" << std::endl;
		castHealingSpell(); 
		return false;
	};
	std::string interact(){
		return "Whenever you're low on health, come to me and I will heal you!";
	};
};

#endif