#include "game.hpp"

/**
TODO: 

*/

Game::Game(){
	finished = false;

}

Game::~Game(){
	delete rooms;
}

void Game::welcome(){
	std::cout << std::endl; //<< std::endl;
	std::cout << "Hello and welcome to Adventure Time!" << std::endl;
	std::cout << "This magical place is flourishing with secrets and hidden treasures." << std::endl;
	std::cout << "Your goal is to find the key and reach the locked room!" << std::endl;
	std::cout << "Beware though! Your health might run out. Recharge at base if you end up low!" << std::endl;
	std::cout << "Please enter your name: ";
	std::string inputLine;
	getline(std::cin, inputLine);
	player.setName(*parser.split(inputLine));
	player.changeRoom(*rooms->gardens1);
	std::cout << "You now venture on and begin your quest..." << std::endl;
	std::cout << "Type \"commands\" to see what you can do!" << std::endl;


	//std::cout << std::endl;

}


void Game::start(){
	welcome();
	//std::string * veca = parser.split("hello and welcome");
	//std::cout << veca[0] << veca[1] << veca[2] << std::endl;
	while(!finished){
		int command = parser.parse();
		finished = processCommand(command);	
	}
}


bool Game::processCommand(int command){
	//Regex regex;
	std::string direction;
	std::string possibleD = player.position()->getExits();
	std::replace(possibleD.begin(), possibleD.end(), ' ', '|');
	possibleD.erase(std::remove(possibleD.begin(), possibleD.end(), ','), possibleD.end());
	possibleD.erase(std::remove(possibleD.begin(), possibleD.end(), '\n'), possibleD.end());

	switch(command){
		case Parser::GO_C:
//			std::cout << "Please enter the travel direction: ";
//			std::cin >> direction;
			direction = parser.getSecondWord();
			if(std::regex_match(direction, std::regex(possibleD))){
				player.position()->playerP(false);
				player.go(direction);
				player.position()->playerP(true);
				player.position()->unlockConditions();

				if(player.position()->returnName() == "Victory Room!" && rooms->forest1->hasLoot()){
					std::cout << "You try to go south but realize there's something missing!" << std::endl;
					player.position()->playerP(false);
					player.go("return");
					player.position()->playerP(true);

				} else {
					std::cout << "You enter: " << player.position()->returnName() << std::endl;
				}
				std::cout << player.position()->description() << std::endl;
				if(player.position()->description() == "There's no way to get out!" || player.position()->description() == "You are victorious!"){
					break;
				}
				player.decreaseHealth(player.position()->temperature(player.getHealth()));
					if(player.getHealth() <= 0){
						std::cout << "Game over! Your health is too low" << std::endl;
						break;
					}
			//	std::cout << "Your commands in this room are: " << std::endl;
			//	player.position().getCommands();

				//HERE EVERY TIME WE SHULD MAKE THE ACTORS DO THEIR INTERACTION. 
				// I.e Wizard heals, Civilian gives you health buff. Monster fights!
				std::cout << "Here are your new exits: " << player.position()->getExits();
				
				std::string actors = player.position()->getActors();
				if(actors != ""){
					//std::cout << "test"<<actors << std::endl;
					player.position()->actorsInteract();
				}
				if(player.getHealth() <= 0){
					std::cout << "Game over! Your health is too low" << std::endl;
					break;
				}
				//player.decreaseHealth();

			} else {
				//std::cout << std::endl;
				//std::cout << "possibleD: " << possibleD << std::endl;
				//std::cout << "command:" << direction << std::endl;
				
				std::cout << "Pick a correct direction! You cannot go '" << direction << "' in this area." << std::endl;
				std::cout << "Here are your possible exits: " << player.position()->getExits();
			}
			return false;
		case Parser::PICKUP_C:
			//std::cout <<"Test0" << std::endl;
			if(std::regex_match(parser.getSecondWord(), std::regex(player.position()->getAllLoot()))){
				//&
			//	std::cout << "TestA" << std::endl;
				player.addItem(*player.position()->getLoot(parser.getSecondWord()));
			//	std::cout << "TestB" << std::endl;
			
				player.position()->getLoot(parser.getSecondWord())->description();
			//	std::cout << "TestC" << std::endl;

				player.position()->removeLoot(player.position()->getLoot(parser.getSecondWord()));

			} else {
				std::cout << "That item does not exist in this room!" << std::endl;
			}

			return false;
		case Parser::EXAMINE_C:
			player.examine();
			return false;
		case Parser::QUIT_C:
			quit();
			return true;
		case Parser::COMMANDS_C:
			player.position()->getCommands();
			return false;
		case Parser::DIRECTION_C:
			player.possibleDirections();
			return false;
		case Parser::BACKPACK_C:
			if(player.printBackpackContents()){}
			else {std::cout << "Your backpack is empty!" << std::endl;}
			return false;
		case Parser::WHEREAMI_C:
			std::cout << "You are in the " << player.position()->returnName() << " area."<< std::endl;
			return false;
		case Parser::WHOAMI_C:
			std::cout << player.returnName() << std::endl;
			return false;
		case Parser::TALK_C:
		// IF THIRD WORD MATCHES ONE OF POSSIBLE ACTORS IN THIS CURRENT ROOM, shoot talk on that actor.
		// Else return "That character does not exist here!"
			if(parser.getThirdWord() == player.returnLowerName()){  // && yourname is not part of the list of possible names.
				std::cout << "y u talk 2 ur self " << std::endl;
			} else {
				std::string nameList = player.position()->getActors();
				transform(nameList.begin(), nameList.end(), nameList.begin(), ::tolower);

				//std::cout << "nameList" << nameList << " actr" << parser.getThirdWord() << std::endl;
				if(parser.getThirdWord() == nameList && parser.getThirdWord() != ""){
					std::cout << "You talk to " << parser.getThirdWord() << "." << std::endl;
					player.position()->talkToActor(nameList);
				} else {
					std::cout << "There is no one called \'" << parser.getThirdWord() << "\' in this room!" << std::endl;
				}
			}
			return false;
		case Parser::HEALTH_C: 
			std::cout << "Your health is: "<<player.getHealth() << std::endl;
			if(player.getHealth() <= 10){
				std::cout << "You should head to base!" << std::endl;
			}
			return false;
		case -1:
			std::cout << "Please enter a proper command. \nType 'commands' for all possible commands in this area!" << std::endl;
			return false;
		default:
			return true;
	}
	return true;
}

void Game::quit(){
	//Delete all objects.
	std::cout << "See you next time!" << std::endl;
	//delete rooms;
}