#include "traproom.hpp"


Traproom::Traproom(){

}

int Traproom::temperature(int pH){
	int superH = 0;
	if(superH > 30){
		superH = pH % 20;
	} else {
		return 5;
	}
	return superH;
}
std::string Traproom::description(){
	if(count >= 1){
	return "Oh no! It's a trap! You should've died here... but a staircase appears. Don't do it again";
	} 
	return "There's no way to get out!";
}
void Traproom::changeDes(std::string str){
		output = str;
}
void Traproom::lootDescription(){
	std::cout <<"There is no loot in this room!" << std::endl;
}
bool Traproom::unlockConditions() {
	if(playerPresent == true){
		--count;
	}
	return true;

}