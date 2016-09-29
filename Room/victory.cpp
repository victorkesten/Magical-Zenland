#include "victory.hpp"


Victory::Victory(){


}
int Victory::temperature(int pH){
	return 0;
}
std::string Victory::description(){
	//exit(1);
	return "You are victorious!";
}
void Victory::changeDes(std::string str){
		output = str;
}
void Victory::lootDescription(){

}
bool Victory::unlockConditions() {
	locked = true;

	return true;

}