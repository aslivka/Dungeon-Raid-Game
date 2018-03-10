/******************************************************************
** Author: 	  		Artem Slivka
** Date: 	  		08/9/17
** Description: 	Batcave.hpp is the header file for derived class 
**		  			Batcave. It contains function declaration for 
**					the class.
******************************************************************/

#ifndef BATCAVE_HPP
#define BATCAVE_HPP
#include "Space.hpp"

class Batcave : public Space
{

public:
	Batcave(int floorNum);
	~Batcave();
	void introduction();
	virtual void drop();
	virtual void exit();	
};

#endif 
