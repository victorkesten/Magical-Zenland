#include "backpack.hpp"


Backpack::Backpack(){
	maxWeight = 10.0;
	slot = 0;
}

Backpack::Backpack(double maxW){
	maxWeight = maxW;
	slot = 0;
}



bool Backpack::addItem(Item & item){
	Item * tempP = &item;
		if((currentWeight + tempP->weight()) > maxWeight){
		return false;
	}
	backpack[slot] = tempP;
	currentWeight += tempP->weight();
	slot++;
	return true;
}
bool Backpack::removeItem(Item * item){
	int i = 0;
	while(i < 20){
		if(item == backpack[i]){
			while((i+1) <20){
				backpack[i] = backpack[i+1];
				i++;
			}
			return true;
		}
		i++;
	}

	for(auto it : backpack){
		if(item == it){

			return true;
		}
	}
	return false;
}
double Backpack::returnWeight() const{
	return 0;
}

double Backpack::returnMaxWeight() const {
	return maxWeight;
}

void Backpack::description() const{
	std::cout << "You carry stuff in this thing" << std::endl;
}

void Backpack::setWeight(int i){
	maxWeight = i;
}
std::string Backpack::returnContent(){
	int i = 0;
	std::string returnString = "Your backpack contains: \n";
	while(i <slot){
		returnString += std::to_string(i+1) + ": " + backpack[i]->name() + "\n";
		i++;
	}
	returnString = returnString.substr(0, returnString.size()-1);
	return returnString;
}