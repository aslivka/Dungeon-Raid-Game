/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/31/17
** Description:		Player.cpp is the function implementation file
**					for class Player.It contains custom attack
**					and defend functions for this creature.
******************************************************************/

#include "Player.hpp"

/*********************************************************************
** Description:		This is the default constructor for class Player
*********************************************************************/
Player::Player()
{
	name = "Human explorer";
	numAttackDies = 2;
	numAttackSides = 6;
	numDefDies = 2;
	numDefSides = 6;
	armor = 0;
	strength = 100;
	inventory = new List();
	haveGrail = false;
}

/*********************************************************************
** Description:		This is the default destructor for class Player.
*********************************************************************/
Player::~Player()
{
	//Clearing inventory
	if (inventory != NULL)
	{
		delete inventory;
		inventory = NULL;
	}
}

/*********************************************************************
** Description:		This function calculates the attack damage from
**					Player object.
*********************************************************************/
int Player::attack()
{
	attackPoints = attackRoll();
	cout << " attacks for " << attackPoints << " pts." << endl;
	return attackPoints;
}

/*********************************************************************
** Description:		This function calculates the strength points lost
**					by Player object.
*********************************************************************/
void Player::defend(int opponentAttack)
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
		//cout << name << endl;
		cout << "Start strength: " << startingStrength << " pts." << endl;
		cout << "defense: " << defense << ", ";
		cout << "armor: " << armor << ", ";
		cout << "damage: " << damage << endl;
		cout << "Final strength: " << strength << " pts." << endl;
	
	//Resetting damage stat for next round.
	damage = 0;
}

/*********************************************************************
** Description:		This function adds an item to player's inventory.
**					Only allows non-duplicates.
*********************************************************************/
void Player::addItem(Item* newItem)
{
	if (inventory->searchList(newItem->getName()) == -1)
	{
		inventory->addItem(newItem);
	}

	else
	{
		cout << "Error! You cannot pick up a duplicate item." << endl;
	}
}

/*********************************************************************
** Description:		This function displays items in player's inventory.
**	
*********************************************************************/
void Player::displayInventory()
{
	inventory->printList();
}

/*********************************************************************
** Description:		This function removes all items in player's inventory.
**
*********************************************************************/
void Player::clearInventory()
{
	inventory->clearList();
}

/*********************************************************************
** Description:		This function checks if Grail is in player's inventory.
**
*********************************************************************/
bool Player::getGrail()
{
	if (inventory->searchList("Holy Grail - source of immortality") != -1)
	{
		haveGrail = true;
	}
	else
	{
		haveGrail = false;
	}
	return haveGrail;
}

/*********************************************************************
** Description:		This function checks player has the 2 unique items
**					before going to floor 6
*********************************************************************/
bool Player::itemsPresent()
{
	int item1Found = inventory->searchList("vial of vampire blood");
	int item2Found = inventory->searchList("Medusa scale");

	//If items aren't found in inventory
	if (item1Found == -1 || item2Found == -1)
	{
		return false;
	}

	//If found in inventory
	else
	{
		return true;
	}
}

/*********************************************************************
** Description:		This function returns the desired stat for player
**					character.
*********************************************************************/
int Player::getStats(string stat)
{
	if (stat == "numAttackDies")
	{
		return numAttackDies;
	}
	if (stat == "numAttackSides")
	{
		return numAttackSides;
	}

	if (stat == "numDefDies")
	{
		return numDefDies;
	}
	
	if (stat == "numDefSides")
	{
		return numDefSides;
	}
	if (stat == "armor")
	{
		return armor;
	}

	if (stat == "monsters killed")
	{
		return numMonstersDead;
	}
}

/*********************************************************************
** Description:		This function increments num of monsters killed
**					for player.
*********************************************************************/
void Player::incrementMonsterKilled()
{	
	if (numMonstersDead <= 4)
	{
		numMonstersDead++;
	}
}
