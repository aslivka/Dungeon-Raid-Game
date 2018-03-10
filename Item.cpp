/******************************************************************
** Author: 			Artem Slivka
** Date: 		    07/15/17
** Description:		Item.cpp is the function implementation file
**					for class Item. It allows a user to set the
**					the parameters for item, for example, item name
**					item quantity, item unit price, etc.
******************************************************************/

#include "Item.hpp"		//Link to class header

/*********************************************************************
** Description:		This is a default constructor for Item class.
*********************************************************************/
Item::Item()
{
	m_itemName = "";
	m_quantity = 0;
}

/*********************************************************************
** Description:		This constructor sets the parameters for the Item
**					object, as entered by user.
*********************************************************************/
Item::Item(string itemName, int quantity)
{
	m_itemName = itemName;
	m_quantity = quantity;
}

/*********************************************************************
** Description:		This is the destructor for Item.
*********************************************************************/
Item::~Item()
{

}
/*********************************************************************
** Description:		This function returns the name for the item object.
*********************************************************************/
string Item::getName()
{
	return m_itemName;
}


/*********************************************************************
** Description:		This function returns the quantity for the item
**					object.
*********************************************************************/
int Item::getQty()
{
	return m_quantity;
}

/*********************************************************************
** Description:		This function sets quantity for the item object.
*********************************************************************/
void Item::setQty(int quantity)
{
	m_quantity = quantity;
}

/*********************************************************************
** Description:		This function prints all the parameters for the 
**					item object, each on a new line for readability.
*********************************************************************/
void Item::printItem()
{
	cout << "Item name: \t" << getName() << endl;
	cout << "Quantity: \t" << getQty() << endl;

	cout << endl;
}

/*********************************************************************
** Description:		This function overloads the == operator. It
**					compares a user's new item to item from the list.
*********************************************************************/
//bool operator==(Item newItem, Item listItem)
//{
//	bool duplicate = (newItem.getName() == listItem.getName());
//	return duplicate;
//}
//
