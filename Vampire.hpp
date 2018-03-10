/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Vampire.hpp is the header file for class
**					Vampire. It contains function declaration
**					for the class.
******************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Creature.hpp"

class Vampire : public Creature
{

public:
	Vampire();
	~Vampire();
	virtual int attack();
	virtual void defend(int opponentAttack);
	bool getCharm();
};

#endif
