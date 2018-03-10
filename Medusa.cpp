/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Medusa.cpp is the function implementation file
**					for class Medusa. It contains custom attack
**					and defend functions for this creature.
******************************************************************/

#include "Medusa.hpp"

/*********************************************************************
** Description:		This is the default constructor for class Medusa.
**
*********************************************************************/
Medusa::Medusa()
{
	name = "Medusa";
	numAttackDies = 2;
	numAttackSides = 6;
	numDefDies = 1;
	numDefSides = 6;
	armor = 3;
	strength = 8;
}

/*********************************************************************
** Description:		This is the default destructor for class Medusa.
**
*********************************************************************/
Medusa::~Medusa()
{

}

/*********************************************************************
** Description:		This function calculates the attack damage from
**					Medusa object.
*********************************************************************/
int Medusa::attack()
{
	attackPoints = attackRoll();
	
	//Checking for glare effect activation
	if (attackPoints == 12 || attackPoints == 1)
	{
		cout << " activates Glare!" << endl;
		attackPoints = 100;
	}

	//Otherwise, normal attack
	else
	{
		cout << " attacks for " << attackPoints << " pts." << endl;
	}

	return attackPoints;
}

/*********************************************************************
** Description:		This function calculates the strength points lost
**					by Medusa object.
*********************************************************************/
void Medusa::defend(int opponentAttack)
{
	defense = defenseRoll();
	int startingStrength = strength;
	int tempDamage = opponentAttack - defense - armor;

	//Removing chance of negative damage
	if (tempDamage >= 0)
	{
		damage = tempDamage;
		strength -= damage;
	}

	//Printing defense results/stats
	cout << "Start strength: " << startingStrength << " pts." << endl;
	cout << "defense: " << defense << ", ";
	cout << "armor: " << armor << ", ";
	cout << "damage: " << damage << endl;
	cout << "Final strength: " << strength << " pts." << endl;

	//Resetting damage stat for next round.
	damage = 0;
}
