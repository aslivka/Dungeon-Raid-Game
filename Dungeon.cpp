/******************************************************************
** Author: 			Artem Slivka
** Date: 		    08/9/17
** Description:		Dungeon.cpp is the function implementation file
**					for class Dungeon. It stores the linked list
**					of floors in dungeon.
******************************************************************/

#include "Dungeon.hpp"

/*********************************************************************
** Description:		This is the default constructor for class Dungeon.
**
*********************************************************************/
Dungeon::Dungeon()
{
	back = NULL;
	front = NULL;
	createList();
}

/*********************************************************************
** Description:		This is the default destructor for class Dungeon.
**
*********************************************************************/
Dungeon::~Dungeon()
{
	//Removing front element one iteration at a time
	//until both front/back point to null, indicating empty list
	while (front != NULL && back != NULL)
	{
		removeFront();
	}
}

/*********************************************************************
** Description:		This function creates a new Space node and adds it
**					to the list. The back pointer should point to the
**					newly created node at the back of the queue.
*********************************************************************/
void Dungeon::addBack(Space* nextNode)
{
	//If the initial list is empty
	if (isEmpty() == true)
	{
		//Creating new temporary node
		Space* newNode = nextNode;

		//First assigning the node's address to back/front
		back = newNode;
		front = back;

		//Setting prev/next pointers
		back->east = front;
		front->west = back;

		newNode = NULL;
	}

	else if (isEmpty() == false)
	{
		//Creating 2 temporary pointers for swapping values
		Space* newBack = nextNode;

		//Assigning back pointer to point forward to new
		//temp node 
		back->east = newBack;

		//Assigning new node to point back to old back node address
		//This will allow the doubly circular link
		newBack->west = back;

		//Re-assigning old back node to point to new node
		//since we just increased the list size by 1
		back = newBack;

		//Connecting the end of new list to front of list in forward 
		//direction
		back->east = front;

		//Connecting the end of new list to front of list in reverse
		//direction
		front->west = back;

		newBack = NULL;
	}
}


/*********************************************************************
** Description:		This function creates a list of dungeon rooms

*********************************************************************/
void Dungeon::createList()
{
	Space* floor1 = new Batcave(1);
	Space* floor2 = new Swamp(2);
	Space* floor3 = new Batcave(3);
	Space* floor4 = new Swamp(4);
	Space* floor5 = new Batcave(5);
	Space* floor6 = new Altar(6);
	addBack(floor1);
	addBack(floor2);
	addBack(floor3);
	addBack(floor4);
	addBack(floor5);
	addBack(floor6);
	
	front->west = NULL;
	back->east = NULL;

}
/*********************************************************************
** Description:		This function returns the current value at the front
**					of the queue, when the list isn't empty. Otherwise,
**					it prints a message.
*********************************************************************/
//int Queue::getFront()
//{
//	//Wanted to add check for empty queue inside function
//	//but compiler gave a warning about not returning value
//
//	return front->value;
//}


/*********************************************************************
** Description:		This function returns the node address at the front
**					of the queue, when the list isn't empty. 
*********************************************************************/
Space* Dungeon::getFront()
{
	return front;
}

/*********************************************************************
** Description:		This function returns the node address at the back
**					of the queue, when the list isn't empty.
*********************************************************************/
Space* Dungeon::getBack()
{
	return back;
}

/*********************************************************************
** Description:		This function removes the node that front pointer
**					is pointing to. Then, the front pointer points
**					to the new first node in the front of the queue.
*********************************************************************/
void Dungeon::removeFront()
{
	//If list empty, do nothing
	if (isEmpty() == true)
	{
		cout << "The queue is empty." << endl;
	}

	//If list has 1 element, then free memory using one of the
	//pointers front/back. Both point to the same location.
	else if (isEmpty() == false && front == back)
	{
		delete front;
		front = NULL;
		back = NULL;
	}

	//If list has 2 or more elements
	else if (isEmpty() == false && front != back)
	{
		//Storing old location of front node 
		//for later deletion from heap
		Space* tempNode = front;

		front = front->east;
		front->west = back;
		back->east = front;

		//Deleting memory for old front node
		delete tempNode;
		tempNode = NULL;
	}
}

/*********************************************************************
** Description:		This function displays the current queue of values
**					depending on the direction chosen.
*********************************************************************/
void Dungeon::displayQueue(string direction)
{
	if (isEmpty() == true)
	{
		cout << "The queue is empty." << endl;
	}

	else
	{
		if (direction == "forward")
		{
			Space* tempNode = front;
			//cout << endl;
			cout << "Displaying queue contents (forward direction)" << endl;

			//Printing entire list
			do
			{
				cout << tempNode->getName() << " ";
				tempNode = tempNode->east;
			} while (tempNode != NULL);

			cout << endl;
		}
		if (direction == "reverse")
		{
			Space* tempNode = back;
			//cout << endl;
			cout << "Displaying queue contents (backward direction)" << endl;

			//Printing entire list
			do
			{
				cout << tempNode->getName() << " ";
				tempNode = tempNode->west;
			} while (tempNode != NULL);

			cout << endl;
		}
	}
}

/*********************************************************************
** Description:		This function checks if the queue is empty.
**
*********************************************************************/
bool Dungeon::isEmpty()
{
	//If front and back nodes are
	//pointing to memory location(s), 
	//list isn't empty
	if (front != NULL && back != NULL)
	{
		return false;
	}

	//Otherwise, the front/back = NULL
	//since that's how they're initialized in Node constructor
	else
	{
		return true;
	}
}

/*********************************************************************
** Description:		This function displays all of the node's parameters.
**					It was used primarily for debugging purposes.
*********************************************************************/
void Dungeon::displayNode(Space* input, string name)
{
	if (isEmpty() == true)
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		cout << name << ":\t";
		cout << "address:" << input << "\t";
		cout << input->west << " " << input->getName() << " " << input->east << endl;
	}
}

