/******************************************************************
** Author: 			Artem Slivka
** Date: 			08/9/17
** Description:		Batcave.cpp is the function implementation file
**					for class Batcave. It contains the floor where
**					the user fights against a vampire monster.
******************************************************************/

#include "Batcave.hpp"
/*********************************************************************
** Description:		This default constructor sets the important member
**					variables for class to pre-set values.
*********************************************************************/
Batcave::Batcave(int floorNum): Space("Batcave")
{
	createCreature(1);
	floorNumber = floorNum;
}

/*********************************************************************
** Description:		This is the destructor for Batcave class.
**
*********************************************************************/
Batcave::~Batcave()
{
	if (player2 != NULL)
	{
		delete player2;
		player2 = NULL;
	}
}

/*********************************************************************
** Description:		This function prints the introduction for the floor
**
*********************************************************************/
void Batcave::introduction()
{
	cout << "Welcome to floor #" << floorNumber  << ": " << getName() << endl;
	if (player1 != NULL)
	{
		cout << "Explorer's current strength is: " << player1->getStrength() << endl;
	}

}

/*********************************************************************
** Description:		This function manages the creature's item
**					drop for this floor.
*********************************************************************/
void Batcave::drop()
{
	//If player kills the monster
	if (winner == 1)
	{
		//Starting prompt
		cout << "The vampire dropped a vial of its blood." << endl;
		char input;

		//Prompting to put item into inventory
		cout << endl;
		cout << "Do you want to pick up this item? y/n" << endl;
		input = getAChar();

		//If yes, add item to player's inventory
		if (input == 'y')
		{
			static_cast<Player*>(player1)->addItem(new Item("vial of vampire blood", 1));
		}
	}
}

/*********************************************************************
** Description:		This function prints the exit message for the floor.
**
*********************************************************************/
void Batcave::exit()
{
	cout << "You have finished exploring floor #" << floorNumber << ", Batcave!" << endl;
	if (player1 != NULL)
	{
		cout << "Explorer's current strength is: " << player1->getStrength() << endl;
	}

}