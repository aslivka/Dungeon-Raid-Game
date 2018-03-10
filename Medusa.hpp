/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Medusa.hpp is the header file for class
**					Medusa. It contains function declaration
**					for the class.
******************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp"

class Medusa :	public Creature
{
public:
	Medusa();
	~Medusa();
	virtual int attack();
	virtual void defend(int opponentAttack);
};

#endif