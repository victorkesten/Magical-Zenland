#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
class Item{

protected:
	double mWeight;
	std::string mName;
	int itemID;

	enum {
		KEY,
		TEST,
		HEALTH,
		BACKPACK
	};

public:
	Item();
	Item(double, std::string, int);


	std::string name() const;
	double weight() const;
	virtual int getType() const = 0;

	//virtual void description(){std::cout << "generic item" << std::endl;};
	virtual void description() const = 0;
	bool operator==(const Item &);
	//bool operator=(const Item &);
	bool setID(int);
	int getID() const;
	bool setName(std::string);
	bool setWeight(double );
};


#endif