#ifndef RoomCreator_H
#define RoomCreator_H
//#include "room.hpp"
#include "gardens.hpp"
#include "headquarters.hpp"
#include "victory.hpp"
#include "forest.hpp"
#include "traproom.hpp"
#include "../Item/test.hpp"
#include "../Item/key.hpp"
#include "../Actor/wizard.hpp"
#include "../Actor/civillian.hpp"
#include "../Actor/ogre.hpp"
#include "../player.hpp"

#include <iostream>


class RoomCreator{

public:
	//ROOMS
	Gardens * gardens1 = new Gardens();
	Headquarters * hq1 = new Headquarters(); // Floor 1
	Headquarters * hq2 = new Headquarters(); // Floor 2
	Gardens * gardens2 = new Gardens();
	Gardens * gardens3 = new Gardens(); // Exit wEst
	Forest * forest1 = new Forest();
	Forest * forest2 = new Forest();
	Traproom * traproom1 = new Traproom();
	Victory * vc = new Victory();

	//
	//Room & roomList[9];

	//ITEMS
	Key * key = new Key();
	Test * a = new Test(); //(5.0, "test", 0);
	//Test * b = new Test(1, "test1", 5);

	Wizard * wiz1;
	Civillian * civ1;
	Ogre * ogre1;
	RoomCreator(Player & p){

		wiz1 = new Wizard(2, "YenSid", p);
		civ1 = new Civillian(1, "Mickey", p);
		ogre1 = new Ogre(p);

		gardens1->setRoomName("Gardens");
		hq1->setRoomName("Headquarters F1");
		hq2->setRoomName("Headquarters F2");
		gardens2->setRoomName("Waterfall");
		gardens3->setRoomName("Gardens West");
		forest1->setRoomName("Forest Thicket");
		forest2->setRoomName("Deep Forest");
		traproom1->setRoomName("Trap!");
		vc->setRoomName("Victory Room!");

		gardens1->setExits("north",*hq1);
		gardens1->setExits("east",*gardens2);
		gardens1->setExits("west",*gardens3);
		hq1->setExits("south",*gardens1);
		hq1->setExits("up", *hq2);
		hq2->setExits("down", *hq1);
		gardens2->setExits("west",*gardens1);
		//gardens2.setExits("west", gardens3);
		
		gardens3->setExits("east",*gardens1);
		gardens3->setExits("west",*forest1);
		forest1->setExits("east", *gardens3);
		forest1->setExits("south", *forest2);
		forest2->setExits("north", *forest1);
		forest2->setExits("south", *vc);
		forest2->setExits("west", *traproom1);
		//!!!!!!!!!!!!!!!!!!
		traproom1->setExits("up", *forest2);
		vc->setExits("return", *forest2);
		//vc.locked(true);
		gardens1->changeDes("Outside in the main gardens area.");
		hq1->changeDes("This is the first floor of your base of operations.");
		hq2->changeDes("This is the second floor of your base of operations.");
		gardens2->changeDes("The waterfall of eternal life!");
		gardens3->changeDes("The outer rims of the Gardens. Danger lies ahead!");
		forest1->changeDes("Look around a bit... Maybe you will find something that opens doors.");
		forest2->changeDes("The deep forest is scary... Mind your step!");


		//west west down west down
		// West of down. Trap Room. Insta ded
		// Items. 
		//Test a(5.0, "test", 0);
		a->setWeight(5.0);
		a->setName("test");
		a->setID(0);
		// b.setWeight(1.0);
		// b.setName("testB");
		// b.setID(1);
		key->setWeight(2.5);
		key->setName("key");
		key->setID(1);
		
		gardens1->addloot(*a);
		//hq1->addloot(*b);
		forest1->addloot(*key);
		//Test b(1.0, "TestB", 1);
		// gardens1.addloot(&b);

		hq2->addActor(*wiz1);
		gardens2->addActor(*civ1);
		forest1->addActor(*ogre1);
	}

	~RoomCreator(){
		delete gardens1;
		delete gardens2;
		delete gardens3;
		delete hq1;
		delete hq2;
		delete forest1;
		delete forest2;
		delete traproom1;
		delete vc;

		delete wiz1;
		delete civ1;
		delete ogre1;
		delete a;
		//delete b;
		delete key;
	}
};

#endif