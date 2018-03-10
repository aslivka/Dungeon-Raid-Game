/******************************************************************
** Author: 			Artem Slivka
** Date: 			08/9/17
** Description:		DungeonRaid.cpp is the function implementation file
**					for class DungeonRaid. It manages the entire
**					gameplay for the program.
******************************************************************/

#include "DungeonRaid.hpp"

/*********************************************************************
** Description:		This default constructor sets the important member
**					variables for class to pre-set values.
*********************************************************************/
DungeonRaid::DungeonRaid()
{
	floors = NULL;
	currentFloor = NULL;
	humanPlayer = NULL;
	setGameMenus();
}

/*********************************************************************
** Description:		This is the destructor for DungeonRaid class.
**
*********************************************************************/
DungeonRaid::~DungeonRaid()
{
	//Freeing all dynamic memory
	clearDungeon();

	if (gameMenu != NULL)
	{
		delete gameMenu;
		gameMenu = NULL;
	}

	if (floorMenu != NULL)
	{
		delete floorMenu;
		floorMenu = NULL;
	}
}

/*********************************************************************
** Description:		This function displays the introduction and 
**					for the game.
*********************************************************************/
string DungeonRaid::introduction()
{	
	string passBack = "";
	passBack += "\n";
	passBack += "||=============================================================||\n";
	passBack += "||            =====Welcome to DungeonRaid game!=====           ||\n";
	passBack += "||=============================================================||\n";
	passBack += "|| As an explorer, you need to visit 6 floors of the dungeon.  ||\n";
	passBack += "|| The final(6th floor) contains a prize, the Holy Grail.      ||\n";
	passBack += "|| It's a source of immortality.                               ||\n";
	passBack += "|| If you wish to obtain everlasting youth, then you need to:  ||\n";
	passBack += "||     1. defeat 5 monsters                                    ||\n";
	passBack += "||     2. obtain 2 different types of items                    ||\n";
	passBack += "||     3. not die on the way (strength <=0)                    ||\n";
	passBack += "|| After collecting items, you will use them to create Grail   ||\n"; 
	passBack += "|| on floor 6. If you don't meet 3 above conditions at end of  ||\n";
	passBack +=	"|| of game, then you will lose the game!                       ||\n";
	passBack += "||=============================================================||\n";
	return passBack;	
}

/*********************************************************************
** Description:		This function sets the game menus for the game
**					class.
*********************************************************************/
void DungeonRaid::setGameMenus()
{
	//Creating main menu
	gameMenu = new Menu();
	//Setting menu options
	gameMenu->addOption("Play new game.");
	gameMenu->addOption("Quit program.");

	//Creating floor menu
	floorMenu = new Menu();
	//Setting menu options
	floorMenu->addOption("Go to next room.");
	//floorMenu->addOption("Go to previous room.");
	floorMenu->addOption("Display player's inventory.");
	floorMenu->addOption("Display/change player's current stats.");
	floorMenu->addOption("Quit game.");
}

/*********************************************************************
** Description:		This function starts the game program. It displays
**					the introduction and shows menu of options for the
**					player.
*********************************************************************/
void DungeonRaid::start()
{
	cout << introduction();
	int menuChoice;
	
	do
	{
		initDungeon();

		//Printing menu options
		gameMenu->printMenu();	

		//Selecting menu option
		menuChoice = getIntegerRange(1, 2);

		//Set menu option
		gameMenu->setOption(menuChoice);

		//If option to play game is selected
		if (gameMenu->getOption() == 1)
		{
			string status = play();

			//Checking return value from play function
			if (status == "dead" || status == "quit" || status == "win")
			{
				gameMenu->setOption(1);
			}	
		}

		clearDungeon();
	} while (gameMenu->getOption() != 2);

	cout << "Quitting program..." << endl;
}

/*********************************************************************
** Description:		This function starts the game play itself. It starts
**					the playRound for each floor. Then, after player
**					completed a floor, the user is returned to this
**					function to go to the next room until the final
**					floor
*********************************************************************/
string DungeonRaid::play()
{
	int firstTime = 0;
	int menuChoice;
	//Playing first floor
	if (firstTime == 0)
	{
		playFloor("first");
		firstTime++;
	}

	do
	{
		//Printing menu options
		floorMenu->printMenu();		//Selecting menu option
		menuChoice = getIntegerRange(1, 4);

		//Set/select a menu option
		floorMenu->setOption(menuChoice);

		switch (floorMenu->getOption())
		{
		case 1: {
				playFloor("next");
				break;
				}
		//case 2: {
		//		playFloor("previous");
		//		break;
		//		}
		case 2: {
				displayInventory();
				break;
				}
		case 3: {
				displayStats();
				break;
				}
		}
	} while (floorMenu->getOption() != 4 && playerDeath != true && playerWin != true);

	if (playerDeath == true)
	{
		return "dead";
	}

	if (menuChoice == 4)
	{
		return "quit";
	}

	if (playerWin == true)
	{
		return "win";
	}
}

/*********************************************************************
** Description:		This function manages play for all 6 floors
**					in the list.
*********************************************************************/
void DungeonRaid::playFloor(string condition)
{
	//If floor 1
	if (condition == "first")
	{
		currentFloor->introduction();

		//Start attack
		currentFloor->start(humanPlayer);
		currentFloor->drop();
		playerStatus("floor 1-5");
		currentFloor->exit();
	}

	//If next room is selected
	if (condition == "next")
	{
			if (currentFloor->east == NULL)
			{
			cout << "You're at the last floor in the dungeon." << endl;
			currentFloor = floors->getBack();
			}
		
			else
			{
				//If floor 2-5
				if (currentFloor->east != floors->getBack())
				{
					if (playerDeath == false)
					{
					//switch rooms
					currentFloor = currentFloor->east;
					currentFloor->introduction();

					//Start attack
					currentFloor->start(humanPlayer);

					//Check player's status after battle
					currentFloor->drop();
					playerStatus("floor 1-5");
					gameMessage();
						if (playerDeath == false)
						{
							currentFloor->exit();
						}
					}
				}
				//If floor 6
				else if (currentFloor->east == floors->getBack())
				{
					playerStatus("before floor6");
					gameMessage();
					
					if (playerDeath == false)
					{
						currentFloor = currentFloor->east;
						//cout << "You're at the front door at last floor in the dungeon." << endl;
						currentFloor->setPlayer(humanPlayer);
						currentFloor->introduction();
						currentFloor->drop();
						playerStatus("floor 6");
						currentFloor->exit();
						gameMessage();
					}
				}
			}	
	}	

}

/*********************************************************************
** Description:		This function initializes the important objects
**					for the game. This allows one to play another game
**					without quitting the program first.
*********************************************************************/
void DungeonRaid::initDungeon()
{
	//Creating dungeon floor list
	floors = new Dungeon();

	//Setting current floor to first floor
	currentFloor = floors->getFront();

	//Creating human player
	humanPlayer = new Player();
	playerDeath = false;
	playerWin = false;

}

/*********************************************************************
** Description:		This function frees memory for important objects
**					for the game. 
*********************************************************************/
void DungeonRaid::clearDungeon()
{	
	//Clearing floors
	if (floors != NULL)
	{
		delete floors;
		floors = NULL;
	}
	
	currentFloor = NULL;

	//Clearing human player
	if (humanPlayer != NULL)
	{
		delete humanPlayer;
		humanPlayer = NULL;
	}

	playerDeath = false;
	playerWin = false;
}

/*********************************************************************
** Description:		This function checks whether player is alive after
**					each floor battle.
*********************************************************************/
void DungeonRaid::playerStatus(string location)
{
	//If player has strength
	if (location == "floor 1-5")
	{
		if (humanPlayer->getStrength() <= 0)
		{
			playerDeath = true;
			playerWin = false;
		}
	}

	//If player has items and killed all monsters
	else if (location == "before floor6")
	{
		if (static_cast<Player*>(humanPlayer)->itemsPresent() == false)
		{
			cout << "Explorer didn't collect all of the " << endl;
			cout << "required items(vial, scale) before floor 6!" << endl;
			playerDeath = true;
			playerWin = false;

		}

		if (static_cast<Player*>(humanPlayer)->getStats("monsters killed") != 5)
		{
			cout << "Explorer didn't kill all of the " << endl;
			cout << "monsters before floor 6." << endl;
			playerDeath = true;
			playerWin = false;

		}
	}

	//If player did/didn't get the Grail
	else if(location == "floor 6")
	{
		if (humanPlayer->getStrength() > 0 && static_cast<Player*>(humanPlayer)->getGrail() == true)
		{
			playerDeath = false;
			playerWin = true;
		}

		if (humanPlayer->getStrength() > 0 && static_cast<Player*>(humanPlayer)->getGrail() == false)
		{
			playerDeath = true;
			playerWin = false;
		}
	}	
}

/*********************************************************************
** Description:		This function prints message about player losing
**					the dungeon game.
*********************************************************************/
void DungeonRaid::gameMessage()
{
	//Message for losing
	if (playerDeath == true)
	{
		cout << endl;
		cout << "||==================================||\n";
		cout << "||----------EXPLORER DIED!----------||\n";
		cout << "||-----------GAME OVER!-------------||\n";
		cout << "||==================================||\n";
	}

	//Message for winning
	if(playerDeath == false && static_cast<Player*>(humanPlayer)->getGrail() == true)
	{
		cout << endl;
		cout << "||===================================||\n";
		cout << "||-EXPLORER OBTAINED THE HOLY GRAIL!-||\n";
		cout << "||--------------GAME WON!------------||\n";
		cout << "||===================================||\n";
	}
}

/*********************************************************************
** Description:		This function shows player's current inventory list.
**					
*********************************************************************/
void DungeonRaid::displayInventory()
{
	static_cast<Player*>(humanPlayer)->displayInventory();
}

/*********************************************************************
** Description:		This function shows player's current stats.
**
*********************************************************************/
void DungeonRaid::displayStats()
{
	//Initializing stat variables to reduce clutter below
	int numAttackDies = static_cast<Player*>(humanPlayer)->getStats("numAttackDies");
	int numAttackSides = static_cast<Player*>(humanPlayer)->getStats("numAttackSides");
	int numDefDies = static_cast<Player*>(humanPlayer)->getStats("numDefDies");
	int numDefSides = static_cast<Player*>(humanPlayer)->getStats("numDefSides");
	int armor = static_cast<Player*>(humanPlayer)->getStats("armor");
	int numMonsters = static_cast<Player*>(humanPlayer)->getStats("monsters killed");
	
	//Printing player stats
	cout << "Name: " << humanPlayer->getName() << endl;
	cout << "Current strength: " << humanPlayer->getStrength() << " pts." << endl;
	cout << "Armor: " << armor << endl;
	cout << "Num of killed monsters: " << numMonsters << endl;
	cout << "Num of attack dies: " << numAttackDies << endl;
	cout << "Num of attack die sides: " << numAttackSides << endl;
	cout << "Num of def dies: " << numDefDies << endl;
	cout << "Num of def die sides: " << numDefSides << endl;

	//Allowing user to change player's strength
	string choice;
	cout << "Press y/n to change player's strength." << endl;
	choice = getAChar();

	if (choice == "y")
	{
		cout << "Enter player's strength(as integer): " << endl;
		int strength = getIntegerRange(10, 1000);
		cout << "Setting player's strength..." << endl;
		humanPlayer->setStrength(strength);
	}

}

