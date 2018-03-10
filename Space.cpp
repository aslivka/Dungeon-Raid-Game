/******************************************************************
** Author: 			Artem Slivka
** Date: 			08/9/17
** Description:		Space.cpp is the function implementation file
**					for class Space.
******************************************************************/

#include "Space.hpp"

/*********************************************************************
** Description:		This default constructor sets the important member
**					variables for class to pre-set values.
*********************************************************************/

Space::Space(string name)
{
	roomName = name;
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
	player1 = NULL;
	player2 = NULL;
}

/*********************************************************************
** Description:		This is the destructor for Space class.
**					
*********************************************************************/
Space::~Space()
{	
	
}

/*********************************************************************
** Description:		This function returns the name of the room/space.
**					
*********************************************************************/
string Space::getName()
{
	return roomName;
}



/*********************************************************************
** Description:		This function passes in current player into  
**					space object.
*********************************************************************/
void Space::setPlayer(Creature* curPlayer)
{
	player1 = curPlayer;
	playerNames[0] = player1->getName();
}

/*********************************************************************
** Description:		This function creates the creatures in space.
**
*********************************************************************/
void Space::createCreature(int choice)
{
	if (choice == 1)
	{
		player2 = new Vampire();
	}
	if (choice == 2)
	{
		player2 = new Medusa();
	}
	/*if (choice == 3)
	{
		player2 = new Barbarian();
	}*/
	playerNames[1] = player2->getName();
}

/*********************************************************************
** Description:		This function displays the menu for the class.
**					It allows user to play against creature in room, 
**					exit, go to next room.
*********************************************************************/
void Space::start(Creature* curPlayer)
{
	//Passing in the player into the room
	setPlayer(curPlayer);

	//Human player starts first
	playersTurn = 1;

	//Playing against creature.
	string choice;
	cout << "Enter y/n to fight against monster. " << endl;
	choice = getAChar();
	if (choice == "y")
	{
		if (player2->getStrength() <= 0)
		{
			cout << "Monster on this floor is already dead! " << endl;
			cout << "Items can't be dropped!" << endl;
		}

		else
		{
			play();
		}
	}
	else
	{
		cout << "Cancelling fight." << endl;
	}	
}

/*********************************************************************
** Description:		This function manages gameplay for the class.
**					It allows user enter a key to continue each round.
*********************************************************************/
void Space::play()
{
	//Selecting the first player for the game
	//playersTurn = simpleRand(1, 2);

	cout << "Human explorer attacks first." << endl;
	playersTurn = 1;
	int round = 1;
	bool gameWin = true;

	//Playing a round, until one of the players' strength
	//reaches <=0
	do
	{
		cout << endl << "Round " << round << endl;
		gameWin = playRound();
		/*if (gameWin == false)
		{
		string input;
		cout << "Press a key to enter another round" << endl;
		getline(cin, input);
		}*/
		round++;
	} while (gameWin == false);

	cout << endl << "Floor Battle Over!" << endl;
	cout << playerNames[winner - 1] << " won!" << endl;
	setMonsterKilled();
}

/*********************************************************************
** Description:		This function plays a round of the game between
**					2 creatures.
*********************************************************************/
bool Space::playRound()
{
	if (playersTurn == 1)
	{
		//Player 1 attacking
		cout << "Player 1: " << playerNames[0];
		player1->attack();
		//Player 2 defending
		cout << "Player 2: " << playerNames[1] << " defends." << endl;
		player2->defend(player1->getAttack());

		if (player2->getStrength() > 0)
		{
			flipPlayerTurn();
		}
		else
		{
			winner = 1;
		}
	}

	else if (playersTurn == 2)
	{
		//Player 2 attacking
		cout << "Player 2: " << playerNames[1];
		player2->attack();
		//Player 1 defending
		cout << "Player 1: " << playerNames[0] << " defends." << endl;
		player1->defend(player2->getAttack());

		if (player1->getStrength() > 0)
		{
			flipPlayerTurn();
		}
		else
		{
			winner = 2;
		}
	}

	//Returning if game ended
	if (winner != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*********************************************************************
** Description:		This function flips the current turn for the round.
**					If player 1 attacked last round, player 2 will
**					attack this round.
*********************************************************************/
void Space::flipPlayerTurn()
{
	if (playersTurn == 1)
	{
		playersTurn = 2;
	}
	else if (playersTurn == 2)
	{
		playersTurn = 1;
	}
}

/*********************************************************************
** Description:		This function sets the num of monsters killed
**					for human player.
*********************************************************************/
void Space::setMonsterKilled()
{
	if (winner == 1)
	{
		static_cast<Player*>(player1)->incrementMonsterKilled();
	}

}