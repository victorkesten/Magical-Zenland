#include "room.hpp"


void Room::setExits(std::string desc, Room & neighbours){
	exits[desc] = & neighbours;
}

std::string Room::getExits() const{
	//http://stackoverflow.com/questions/4844886/how-to-loop-through-a-c-map			
	std::string returnString;
	for(std::map<std::string, Room*>::const_iterator it = exits.begin(); it != exits.end(); it++){
		returnString += it->first + ", ";
	}

	//Return String - 2 characters. 
	returnString = returnString.substr(0, returnString.size()-2);
	return returnString + "\n";
}

void Room::lockRoom(bool t){
	locked = t;
}

void Room::addRoomCommands(std::string str){
	commandList[commandListIndex] = str;
	commandListIndex++;
}
void Room::playerP(bool v){
	playerPresent = v;
}


void Room::getCommands() const{
	int a = 0;
	while(a < (commandListIndex-1)){
		std::cout << commandList[a] << ", ";
		a++;
	}
	std::cout << commandList[a] <<std::endl;
		// for(auto str : commandList){
		// 	std::cout << str << ", ";
		// }
		// std::cout << std::endl;
}


// Returns a pointer. 
Room * Room::getExit(std::string str){
	return exits[str];
}

void Room::setRoomName(std::string str){
	roomName = str;
}

std::string Room::returnName() const{
	return roomName;
}

//Room loot

// bool Room::addloot(Item * item){
// 	if(roomlootindex <= 10){
// 		roomloot[roomlootindex] = item;
// 		roomlootindex++;
// 		return true;
// 	}
// 	return false;
// }

bool Room::addloot(Item & item){
	if(roomlootindex <= 10){
		roomloot[roomlootindex] = &item;
		roomlootindex++;
		return true;
	}
	return false;
}

// POSSIBLY BROKEN
bool Room::removeLoot(Item * item){
	int a = 0;

	while(a < roomlootindex){
		if (item == roomloot[a]){
			roomloot[a] = roomloot[roomlootindex];
			while(a < roomlootindex-1){
				roomloot[a] = roomloot[a+1];
				a++;
			}
			roomlootindex--;
			return true;
		}
		a++;
	}

	return false;
} 
std::string Room::getAllLoot()const{
	int i = 0;
	std::string returnString = "";
	//std::cout << "asdf"<< roomlootindex<< std::endl;
	while(i <roomlootindex){
		returnString += roomloot[i]->name() + "|";
		++i;
	}
	//std::cout << "Loot:" <<returnString << std::endl;

	return returnString;
}

Item * Room::getLoot(const std::string nName){
	int i = 0;

	while(i <=roomlootindex){
		if(roomloot[i]->name() == nName){
			return roomloot[i];
		}
	}
	return roomloot[0];
}

bool Room::hasLoot(){
	if(roomlootindex == 0){
		return false;
	}
	return true;
}


void Room::addActor(Actor & act){
	actors.push_back(&act);
}

bool Room::removeActor(Actor & act){
	int i = 0;
	for(auto a : actors){
		if(*a == act){
			actors.erase(actors.begin() + i);
			return true;
		}
		i++;
	}
	return false;
}

std::string Room::getActors()const{
	std::string returnSTring = "";
	for(auto a : actors){
		returnSTring += a->getName();// + a->getSpeech();
	}
	return returnSTring;
}

void Room::actorsInteract(){
	for(int i = 0; i < actors.size(); ++i){
		actors[i]->action();
		//2std::cout << "HellO" << std::endl;
	}
}

void Room::talkToActor(std::string actorName){
	for(int i = 0; i < actors.size(); ++i){
		std::string tName = actors[i]->getName();
		transform(tName.begin(), tName.end(), tName.begin(), ::tolower);

		if(tName == actorName){
			std::cout << actors[i]->interact() << std::endl;
		}
		//2std::cout << "HellO" << std::endl;
	}
}