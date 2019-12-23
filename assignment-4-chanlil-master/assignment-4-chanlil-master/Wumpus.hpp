/*********************************************************************
** Program Filename: wumpus.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the wumpus header file
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "Event.hpp"
#include <string>

using namespace std;

class Wumpus : public Event{
	public:
		Wumpus();
		string percept();
		int encounter();
};
	
#endif
