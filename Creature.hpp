/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Creature.hpp is the header file for class 
**					Creature. It contains function declaration 
**					for the class.
******************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Utility.hpp"

class Creature
{
protected:
	string name;
	int numAttackDies = 0;
	int numAttackSides = 0;
	int numDefDies = 0;
	int numDefSides = 0;
	int armor = 0;
	int strength = 0;
	int attackPoints = 0;
	int defense = 0;
	int damage = 0;
	
public:
	Creature();
	virtual ~Creature();
	int dieRoll(int min, int max);
	int defenseRoll();
	int attackRoll();
	virtual int attack() = 0;
	virtual void defend(int opponentAttack) = 0;
	int getAttack();
	int getStrength();
	void setStrength(int fstrength);
	string getName();

};

#endif

