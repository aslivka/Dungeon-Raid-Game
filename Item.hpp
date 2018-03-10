/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/15/17
** Description:		Item.hpp is the header file for class Item.
**					It contains function declarations for the class.
******************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Item
{
private:
	string m_itemName;
	int m_quantity;
	
public:
	Item();
	Item(string itemName, int quantity);
	~Item();
	string getName();
	void setQty(int quantity);
	int getQty();
	void printItem();
	//friend bool operator==(Item newItem, Item listItem);

};
#endif 
