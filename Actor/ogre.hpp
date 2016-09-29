#ifndef OGRE_HPP
#define OGRE_HPP
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "../player.hpp"
#include <iostream>
#include <string>

class Ogre : public Actor {
	Player * player;
	int health;
	bool alive;
public:
	Ogre(Player & p){
		health = 40;
		player = &p;
		name = "Ogre";
		alive = true;

	}
	~Ogre(){}

	int getType() const {return OGRE;};


	bool action(){
		if(health > 0){
			std::cout << "HE HA HO. I am the deadly ogre! Fight me!" << std::endl;
			std::cout << "[To fight, guess and type a number between 1 and 50.]" << std::endl;
			std::cout << "[Whoever gets the closest to the correct answer wins.]" << std::endl;
			std::cout << "[The ogre has 40 health. Each turn you can damage 10 health.]" << std::endl;
		}
		while(health > 0 && player->getHealth() >0){
			//Cin, get some rolls. do a roll game thing
			// Guess a number between 0 and 100. 
			// Whoever is closer wins and deals damage. 
			// call fight to damage player;
			std::cout << ">";
			srand(time(NULL));
			int playerGuess, ogreGuess, secret;

			secret = rand() % 100;
			ogreGuess = rand() % 100;
			std::string inputLine = "";
			try{
				getline(std::cin, inputLine);
				//if(inputLine.)
				if(isInteger(inputLine)){
					playerGuess = stoi(inputLine);
					compare(playerGuess, ogreGuess, secret);
				} else {
					std::cout << "Please type in a number between 0-100" << std::endl;
					playerGuess = 0;
				}
				//std::cout << playerGuess;
			} catch(std::invalid_argument){
				std::cout << "Please type in a number between 0-100" << std::endl;
				playerGuess = 0;
			}
			if(player->getHealth() <=0){
				std::cout << "You were slayn by the ogre!" << std::endl;
				break;
			}
		}
		if(health <= 0){
			std::cout << "The ogre is dead! Thank god." << std::endl;
		
		}
		return false;
	};
	bool isInteger(const std::string & s)
	{
	   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

	   char * p ;
	   strtol(s.c_str(), &p, 10) ;

	   return (*p == 0) ;
	}
	void compare(int p, int o, int real){
		int tempP = std::abs(real - p);
		int tempO = std::abs(real - o);

		if(tempO > tempP){
			health-=10;
			std::cout << "The winning number was " << real <<". The ogre guessed " << o << ". You win! You damage the ogre 10 health. The ogre has " << health <<" health left!" << std::endl;
			if(health == 0){
				std::cout << "The ogre died! Continue on with your joruney!" << std::endl;
				std::cout << "Remember, there may be something lying around!" << std::endl;
				//player->position()->description();
				alive = false;
			}
		} else {
			player->decreaseHealth(5);
			std::cout << "The winning number was " << real << ". The ogre guessed " << o << ". You take 5 damage! Your current health is " << player->getHealth() << std::endl;
		}	
	}

	void yell() const{
		std::cout << "RAWR" << std::endl;
	};

	std::string interact(){
		return "ROAR";
	};
};

#endif