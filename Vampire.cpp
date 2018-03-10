/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Vampire.cpp is the function implementation file
**					for class Vampire. It contains custom attack
**					and defend functions for this creature.
******************************************************************/

#include "Vampire.hpp"

/*********************************************************************
** Description:		This is the default constructor for class Vampire.
**
*********************************************************************/
Vampire::Vampire()
{
	name = "Vampire";
	numAttackDies = 1;
	numAttackSides = 12;
	numDefDies = 1;
	numDefSides = 6;
	armor = 1;
	strength = 18;
}

/*********************************************************************
** Description:		This is the default destructor for class Vampire
**
*********************************************************************/
Vampire::~Vampire()
{

}

/*********************************************************************
** Description:		This function calculates the attack damage from
**					Vampire object.
*********************************************************************/
int Vampire::attack()
{
	attackPoints = attackRoll();
	cout << " attacks for " << attackPoints << " pts." << endl;
	return attackPoints;
}

/*********************************************************************
** Description:		This function calculates the strength points lost
**					by Vampire object.
*********************************************************************/
void Vampire::defend(int opponentAttack)
{
	defense = defenseRoll();
	int tempDamage;
	int startingStrength = strength;
	
	//cout << name << endl;
	//Checking for Charm effect
	if (getCharm() == true)
	{
		tempDamage = 0;
	}
	else
	{
	 tempDamage = opponentAttack - defense - armor;
	}
	
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
/*********************************************************************
** Description:		This function returns true if Charm effect is
**					activated by Vampire in defense. It also prints
**					the status state on the screen.
*********************************************************************/
bool Vampire::getCharm()
{
	//Rolling for charm effect
	int charmStatus = dieRoll(1, 2);

	if (charmStatus == 1)
	{
		return false;
	}
	else 
	{
		//Printing effect message
		cout <<  "Vampire activates Charm! Opponent deals no damage" << endl;
		return true;
	}
}
