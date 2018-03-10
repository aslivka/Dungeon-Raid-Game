/******************************************************************
** Author: 			Artem Slivka
** Date: 			08/9/17
** Description:		Altar.cpp is the function implementation file
**					for class Altar.It contains the floor where the
**					user obtains the Holy Grail.
******************************************************************/

#include "Altar.hpp"
/*********************************************************************
** Description:		This default constructor sets the important member
**					variables for class to pre-set values.
*********************************************************************/
Altar::Altar(int floorNum): Space("Altar")
{
	floorNumber = floorNum;
}

/*********************************************************************
** Description:		This is the destructor for Altar class.
**
*********************************************************************/
Altar::~Altar()
{
	if (player2 != NULL)
	{
		delete player2;
		player2 = NULL;
	}
}

/*********************************************************************
** Description:		This function prints the introduction for the floor.
**
*********************************************************************/
void Altar::introduction()
{
	char input;
	
	cout << "Welcome to floor #" << floorNumber << ": " << getName() << endl;
	if (player1 != NULL)
	{
		cout << "Explorer's current strength is: " << player1->getStrength() << endl;
	}
	
	//Releasing gathered items
	do
	{
		cout << "To release the items gathered so far on the altar, press r" << endl;
		input = getAChar();
	} while (input != 'r');

	cout << "Items are taken from inventory and placed on the altar." << endl;
}

/*********************************************************************
** Description:		This function manages the creature's item
**					drop for this floor.
*********************************************************************/
void Altar::drop()
{
	//Creating holy grail
	cout << "...Generating explorer's prize..." << endl;
	cout << "Holy Grail has been created!" << endl;

	char input;
	//Prompting to put item into inventory
	cout << "To get the item and put it in inventory, press g" << endl;
	input = getAChar();

	if (input == 'g')
	{
		//Clearing inventory
		static_cast<Player*>(player1)->clearInventory();

		//Adding holy grail item
		static_cast<Player*>(player1)->addItem(new Item("Holy Grail - source of immortality", 1));
	}
}

/*********************************************************************
** Description:		This function prints the end message for the floor.
**
*********************************************************************/
void Altar::exit()
{
	if (player1->getStrength() > 0 && static_cast<Player*>(player1)->getGrail() == true)
	{
		cout << "You have finished exploring floor #" << floorNumber << ", Altar!" << endl;
		if (player1 != NULL)
		{
			cout << "Explorer's current strength is: " << player1->getStrength() << endl;
		}
	}
}

