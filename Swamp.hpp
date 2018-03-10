/******************************************************************
** Author: 	  		Artem Slivka
** Date: 	  		08/09/17
** Description: 	Swamp.hpp is the header file for derived class 
**		  			Swamp. It contains function declaration for 
**					the class.
******************************************************************/

#ifndef SWAMP_HPP
#define SWAMP_HPP
#include "Space.hpp"

class Swamp : public Space
{

public:
	Swamp(int floorNum);
	~Swamp();
	void introduction();
	virtual void drop();
	virtual void exit();
};

#endif 
