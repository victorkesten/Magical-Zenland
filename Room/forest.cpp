#include "forest.hpp"


Forest::Forest(){


}
int Forest::temperature(int pH){
	if(pH > 10){
		return 8;
	} else {
		return 2;
	}
	return 0;
}
std::string Forest::description(){
	return output;
}
void Forest::changeDes(std::string str){
		output = str;
}
void Forest::lootDescription(){
	if(hasLoot()){
		std::cout << "What do you use to open a door?" << std::endl;	
	} else {
		std::cout << "There is no loot in this room!" << std::endl;
	}

}
bool Forest::unlockConditions() {

	return true;

}