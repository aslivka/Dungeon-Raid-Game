/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Creature.cpp is the function implementation file
**					for class Creature.
******************************************************************/

#include "Creature.hpp"

/*********************************************************************
** Description:		This is the default constructor for class Creature
**					
*********************************************************************/
Creature::Creature()
{

}

/*********************************************************************
** Description:		This is the default destructor for class Creature
**
*********************************************************************/
Creature::~Creature()
{

}

/*********************************************************************
** Description:		This function does a random die roll based on set 
**					parameters for min, max.
*********************************************************************/
int Creature::dieRoll(int min, int max)
{
	return simpleRand(min, max);
}

/*********************************************************************
** Description:		This function does a defense die roll based on set
**					parameters for number of dies, die sides, etc.
*********************************************************************/
int Creature::defenseRoll()
{
	int sumRoll = 0;
	//Rolling defense die i times
	for (int i = 0; i < numDefDies; i++)
	{
		sumRoll += dieRoll(1, numDefSides);
	}
	defense = sumRoll;
	return defense;
}

/*********************************************************************
** Description:		This function does an attack die roll based on set
**					parameters for number of dies, die sides, etc.
*********************************************************************/
int Creature::attackRoll()
{
	int sumRoll = 0;
	//Rolling attack die i times
	for (int i = 0; i < numAttackDies; i++)
	{
		sumRoll += dieRoll(1, numAttackSides);
	}
	attackPoints = sumRoll;

	return attackPoints;
}



/*********************************************************************
** Description:		This function returns the current attack for any 
**					specific creature.
*********************************************************************/
int Creature::getAttack()
{
	return attackPoints;
}

/*********************************************************************
** Description:		This function returns the current strength for any
**					specific creature.
*********************************************************************/
int Creature::getStrength()
{
	return strength;
}

/*********************************************************************
** Description:		This function returns the current name for any
**					specific creature.
*********************************************************************/
string Creature::getName()
{
	return name;
}

void Creature::setStrength(int fstrength)
{
	strength = fstrength;
}