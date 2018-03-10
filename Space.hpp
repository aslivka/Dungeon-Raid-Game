/******************************************************************
** Author: 	  		Artem Slivka
** Date: 	  		08/9/17
** Description: 	Space.hpp is the header file for base class Space
**		  			It contains function declaration for the class.
******************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Menu.hpp"
#include "Item.hpp"
#include "Creature.hpp"
#include "Player.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "Utility.hpp"
//#include "Barbarian.hpp"
using namespace std;

class Space
{
protected:
		
	string roomName;
	int floorNumber;
	//Item* floorItem;
	Creature* player1;		//human player
	Creature* player2;		//monster player
	int creatureChoice = 0;
	int playersTurn;
	int winner = 0;
	string playerNames[2];
	
public:
	Space* north;
	Space* south;
	Space* east;
	Space* west;
	Space(string name);
	virtual ~Space();
	
	//Getter functions
	string getName();
	
	//Setter functions
	virtual void introduction() = 0;
	void setPlayer(Creature* curPlayer);
	void createCreature(int creatureChoice);
	void setMonsterKilled();

	//Gaming functions
	void start(Creature* curPlayer);
	bool playRound();
	void play();
	void flipPlayerTurn();
	virtual void exit() = 0;
	virtual void drop() = 0;

};

#endif 
