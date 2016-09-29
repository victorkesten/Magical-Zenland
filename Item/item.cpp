#include "item.hpp"


Item::Item(){
	mWeight = 1;
	mName = "unknown";
	itemID = -1;
}

//Standard constructor for an item.
Item::Item(double w, std::string n, int id){
	mWeight = w;
	mName = n;
	itemID = id;
}

std::string Item::name() const{
	return mName;
}


// 		 
bool Item::operator==(const Item & copy){
	if(copy.name() == name() && copy.weight() == weight()){
		return true;
	}
	return false;
}

	bool Item::setName(std::string n){
		mName = n;
		return true;
	}

	bool Item::setWeight(double d){
		mWeight = d;
		return true;
	}

double Item::weight() const{

	return mWeight;
}

//Every Item as their own unique item ID. 
bool Item::setID(int id){
	itemID = id;
	return true;
}
//Returns the item ID.
int Item::getID() const{
	return itemID;
}