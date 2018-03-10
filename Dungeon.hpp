/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/15/17
** Description:		Dungeon.hpp is the header file for class Dungeon.
**					It contains function declarations for the class.
******************************************************************/

#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include <stddef.h>		//For NULL definition
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Batcave.hpp"
#include "Swamp.hpp"
#include "Altar.hpp"

class Dungeon
{
	//List pointers
protected:
	Space* front;
	Space* back;

public:
	Dungeon();
	~Dungeon();
	void addBack(Space* nextNode);
	void createList();
	Space* getFront();
	Space* getBack();
	void removeFront();
	void displayQueue(string direction);
	bool isEmpty();
	void displayNode(Space* input, string name);
};
#endif 





