/******************************************************************
** Author: 	  		Artem Slivka
** Date: 	  		08/9/17
** Description: 	DungeonRaid.hpp is the header file for  class
**		  			DungeonRaid. It contains function declaration for
**					the class.
******************************************************************/

#ifndef DUNGEON_RAID_HPP
#define DUNGEON_RAID_HPP
#include <iostream>
#include <stddef.h>		//For NULL definition
#include "Dungeon.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include "Utility.hpp"

class DungeonRaid
{
private:
	Dungeon* floors;
	Space* currentFloor;
	Menu* gameMenu;
	Menu* floorMenu;
	Creature* humanPlayer;
	bool playerDeath = false;
	bool playerWin = false;

public:
	DungeonRaid();
	~DungeonRaid();

	string introduction();
	void setGameMenus();
	void start();
	string play(); 
	void playFloor(string condition);
	void initDungeon();
	void clearDungeon();
	void playerStatus(string location);
	void gameMessage();
	void displayInventory();
	void displayStats();

};

#endif 
