 #include "actor.hpp"

Actor::Actor(){

}
Actor::~Actor(){

}

bool Actor::operator==(const Actor & rhs){
	if(getName() == rhs.getName() && getType() == rhs.getType()){
		return true;
	}
	return false;
}

std::string Actor::getName() const{
	return name;
};

void Actor::setName(std::string name_t){
	name = name_t;
};
