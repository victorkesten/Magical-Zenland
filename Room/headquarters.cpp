#include "headquarters.hpp"

Headquarters::Headquarters(){

}

bool Headquarters::unlockConditions(){
	return true;
}


int Headquarters::temperature(int pH){
	return -5;
}
std::string Headquarters::description(){

	return output;
}

void Headquarters::lootDescription(){
	std::cout << "There is nothing of interest here" << std::endl;
}

void Headquarters::changeDes(std::string str){
	output = str;
}
