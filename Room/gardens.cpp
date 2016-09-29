#include "gardens.hpp"
Gardens::Gardens(){
}

int Gardens::temperature(int pH){
	return 1;
}

bool Gardens::unlockConditions(){
	return true;
}
std::string Gardens::description(){

	return output;
}

void Gardens::changeDes(std::string str){
	output = str;
}


void Gardens::lootDescription(){

	if(hasLoot()){
		std::cout << "A lot of testing was once done in this area." << std::endl;	
	} else {
		std::cout << "There is no loot in this room!" << std::endl;
	}
}