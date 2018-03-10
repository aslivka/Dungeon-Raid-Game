/******************************************************************
** Author: 	  		Artem Slivka
** Date: 	  		08/09/17
** Description: 	Altar.hpp is the header file for derived class 
**		  			Altar. It contains function declaration for 
**					the class.
******************************************************************/

#ifndef ALTAR_HPP
#define ALTAR_HPP
#include "Space.hpp"	

class Altar : public Space
{
		
public:
	Altar(int floorNum);
	~Altar();
	virtual void introduction();
	virtual void drop();
	virtual void exit();
};

#endif 
