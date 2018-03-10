/******************************************************************
** Author: 			Artem Slivka
** Date: 			08/9/17
** Description:		Swamp.cpp is the function implementation file
**					for class Swamp.It contains the floor where the
**					user fights against Medusa monster.
******************************************************************/

#include "Swamp.hpp"
/*********************************************************************
** Description:		This default constructor sets the important member
**					variables for class to pre-set values.
*********************************************************************/
Swamp::Swamp(int floorNum): Space("Swamp")
{
	createCreature(2);
	floorNumber = floorNum;
}

/*********************************************************************
** Description:		This is the destructor for Swamp class.
**
*********************************************************************/
Swamp::~Swamp()
{
	if (player2 != NULL)
	{
		delete player2;
		player2 = NULL;
	}
}

/*********************************************************************
** Description:		This function prints introduction for Swamp class.
**
*********************************************************************/
void Swamp::introduction()
{
	cout << "Welcome to floor #" << floorNumber << ": " << getName() << endl;
	if (player1 != NULL)
	{
		cout << "Explorer's current strength is: " << player1->getStrength() << endl;
	}
}

/*********************************************************************
** Description:		This function manages the creature's item
**					drop for this floor.
*********************************************************************/
void Swamp::drop()
{
	//If player killed monster
	if (winner == 1)
	{
		//Starting drop dialog
		cout << "The medusa dropped one of her scales." << endl;
		char input;

		//Prompting to put item into inventory
		cout << endl;
		cout << "Do you want to pick up this item? y/n" << endl;
		input = getAChar();

		//If yes, add item to player's inventory
		if (input == 'y')
		{
			static_cast<Player*>(player1)->addItem(new Item("Medusa scale", 1));
		}
	}
}

/*********************************************************************
** Description:		This function manages the player's exit from floor.
**					
*********************************************************************/
void Swamp::exit()
{
	cout << "You have finished exploring floor #" << floorNumber << ", Swamp!" << endl;
	if (player1 != NULL)
	{
		cout << "Explorer's current strength is: " << player1->getStrength() << endl;
	}

}