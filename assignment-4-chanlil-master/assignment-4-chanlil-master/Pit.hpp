/*********************************************************************
** Program Filename: pit.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the pit header file
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef PIT_HPP
#define PIT_HPP
#include "Event.hpp"
#include <string>

using namespace std;

class Pit : public Event{
	public:
		Pit();
		string percept();
		int encounter();
};
	
#endif
