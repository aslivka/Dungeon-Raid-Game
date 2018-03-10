/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Player.hpp is the header file for derived class
**					Player. It contains function declaration
**					for the class.
******************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Creature.hpp"
#include "List.hpp"

class Player : public Creature
{
private:
	List* inventory;
	bool haveGrail;
	int numMonstersDead = 0;
	
public:
	Player();
	~Player();
	virtual int attack();
	virtual void defend(int opponentAttack);
	void addItem(Item* newItem);
	void displayInventory();
	void clearInventory();
	bool getGrail();
	bool itemsPresent();
	int getStats(string stat);
	void incrementMonsterKilled();

};

#endif

