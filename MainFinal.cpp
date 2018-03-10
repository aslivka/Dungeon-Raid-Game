/*********************************************************************
** Program name:	FinalProject - DungeonRaid
** Author:			Artem Slivka
** Date:			8/9/17
** Description:		This project creates a game. The purpose of the game
**					is to obtain 2 types of items and kill all of the 
**					monsters. At the end, the player will get a way
**					to become immortal, holy grail.
*********************************************************************/

#include <iostream>
#include <string>
#include "Dungeon.hpp"
#include "DungeonRaid.hpp"
#include "List.hpp"

int main()
{
	DungeonRaid game1;

	game1.start();
	
	cin.get();

	return 0;
}

//Testing list
//List* inventory = new List();
//Item* item1 = new Item("vial of vampire blood", 1);
//inventory->addItem(item1);
//Item* item2 = new Item("Medusa scale", 1);
//inventory->addItem(item2);
//Item* item3 = new Item("Medusa scale", 1);
//inventory->addItem(item3);
//Item* item4 = new Item("vial of vampire blood", 1);
//inventory->addItem(item4);