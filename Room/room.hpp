#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <vector>
#include "../Actor/actor.hpp"
#include "../Item/test.hpp"

class Room {

	protected:
		std::map<std::string, Room *> exits;
		std::string commandList[11]; 
		int commandListIndex = 11;
		bool playerPresent;
		//CHANGE TO POINTER
		// Item * roomLot[10];
		//Item roomloot[10];

		Item * roomloot[10];

		int roomlootindex;
		std::string roomName;
		bool locked;

		std::vector<Actor *> actors = {};

		//template<typename T>
		//std::vector<T *> vinny;


	public:
		Room(){	
			roomlootindex = 0;
			locked = false;
			commandList[0] = "go 'direction'";
			commandList[1] = "examine";
			commandList[2] = "pickup 'item'";
			commandList[3] = "commands";
			commandList[4] = "quit/exit";
			commandList[5] = "directions/exits";
			commandList[6] = "backpack";
			commandList[7] = "whereami";
			commandList[8] = "whoami";
			commandList[9] = "health";
			commandList[10] = "talk to 'name'";


			//"go","examine","pickup","commands","quit","exit", "directions", "backpack", "whereami", "whoami"};
		}
		virtual ~Room(){};


		virtual int temperature(int) = 0;
		virtual std::string description() = 0;
		virtual void changeDes(std::string) = 0;
		void setExits(std::string, Room &);
		std::string getExits() const;
		Room * getExit(std::string);
		void getCommands() const;
		void lockRoom(bool);
		virtual void lootDescription() = 0;
		virtual bool unlockConditions() = 0;
		void playerP(bool);

		void addRoomCommands(std::string);
		void setRoomName(std::string);
		std::string returnName() const;
		//Loot stuff
		//bool addloot(Item * i);
		bool addloot(Item & item);
		bool removeLoot(Item * i); 
		std::string getAllLoot() const;
		Item * getLoot(const std::string);
		bool hasLoot();


		void addActor(Actor & act);
		bool removeActor(Actor & act);

		std::string getActors() const;
		//ALL ACTORS USE INTERACT;
		void actorsInteract();
		void talkToActor(std::string actorName);
};

#endif