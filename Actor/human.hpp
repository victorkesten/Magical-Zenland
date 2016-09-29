#ifndef HUMAN_H
#define HUMAN_H

#include "actor.hpp"
#include <string>

class Human : public Actor {

public:
	Human(){};
	virtual ~Human(){};
	virtual int getType() const = 0;
	virtual bool action() = 0;
	virtual std::string interact() = 0;

	void laugh() const {std::cout << "[" << name << " bursts out in laughter!]" << std::endl;};
};

#endif