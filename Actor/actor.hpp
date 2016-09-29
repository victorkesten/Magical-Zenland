#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>

class Actor {

protected:
	std::string type;
	std::string name = "genericActor";

	enum {
		WIZARD,
		CIVILLIAN,
		OGRE
	};
public: 	

	Actor();
	virtual ~Actor() = 0;
	virtual int getType() const = 0;
	virtual bool action() = 0;
	virtual std::string interact() = 0;

	bool operator==(const Actor & );
	std::string getName() const;
	void setName(std::string);
};

#endif