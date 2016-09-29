#include "player.hpp"
Player::Player(){
	//backpack = new Backpack(20);
	//backpack.setWeight(20);
	bp->setWeight(20);
}


void Player::go(std::string str){
	changeRoom(*position()->getExit(str));
}


void Player::examine() const{
	//Send room spooky description. Give hints about possible items. 
	//std::cout << "This room contains the following loot: " << std::endl;
	currentPosition->lootDescription();
}

Room * Player::position(){
	return currentPosition;
}

void Player::changeRoom(Room & r){
	currentPosition = &r;
}

void Player::setName(std::string str){
	playerName = str;
}


// bool Player::addItem(Item * item){
// 	//backpack->addItem(item);
// 	//item->description();
// 	backpack.addItem(item);
// 	return true;
// }

// bool Player::printBackpackContents(){
// 	//if(backpack->returnContent() == ""){
// 	if(backpack.returnContent() == ""){
// 		return false;
// 	}
// 	//std::cout << backpack->returnContent() << std::endl;
// 	std::cout << backpack.returnContent() << std::endl;
// 	return true;
// }

// bool Player::addItem(Item * item){
// 	//backpack->addItem(item);
// 	//item->description();
// 	bp->addItem(item);
// 	return true;
// }

bool Player::addItem(Item & item){
	//backpack->addItem(item);
	//item->description();
	bp->addItem(item);
	return true;
}

bool Player::printBackpackContents() const{
	//if(backpack->returnContent() == ""){
	if(bp->returnContent() == ""){
		return false;
	}
	//std::cout << backpack->returnContent() << std::endl;
	std::cout << bp->returnContent() << std::endl;
	return true;
}

void Player::possibleDirections() const{
	std::cout << currentPosition->getExits();
}

std::string Player::returnName() const{
	return playerName;
}
std::string Player::returnLowerName() const{
	std::string pn = playerName;
	std::transform(pn.begin(), pn.end(), pn.begin(), ::tolower);
	return pn;
}

void Player::decreaseHealth(int a){
	playerHealth -= a;
}

void Player::setHealth(int newHealth){
	if(newHealth == 75){
		healthUpgrade = true;
	}
	playerHealth = newHealth;
}

bool Player::hasUpgrade() const{
	return healthUpgrade;
}


int Player::getHealth() const{
	return playerHealth;
}

