#ifndef PLAYER_H
#define PLAYER_H

#include "Room/room.hpp"
#include "Room/gardens.hpp"
#include "Room/headquarters.hpp"
#include "Item/backpack.hpp"

class Player {
	std::string playerName;
	int backpackSize;
	int playerHealth = 50;
	bool healthUpgrade = false;
	//Inventory
	//Backpack * backpack;
	//Backpack backpack;
	Backpack * bp = new Backpack();

	//position
	Room * currentPosition;

public:
	Player();
	~Player(){delete bp;};

	void setName(std::string);
	std::string returnName() const;
	std::string returnLowerName() const;

	void go(std::string);
	void changeRoom(Room &);
	Room * position();
	void possibleDirections() const;

//	bool addItem(Item *);
	bool addItem(Item & item);
	bool printBackpackContents() const;
	void examine() const;

	void decreaseHealth(int);
	void setHealth(int);
	bool hasUpgrade() const;
	int getHealth() const;

	//std::string getStats();
};

#endif