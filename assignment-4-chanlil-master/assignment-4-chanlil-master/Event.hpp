/*********************************************************************
** Program Filename: Event.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: This is the event template
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef EVENT_HPP
#define EVENT_HPP
#include <string>

using namespace std;

class Event{
protected:
	string warning;
	int room_type;
public:
	//Events();
	//~Events();
	virtual string percept() = 0;
	virtual int encounter() = 0;
};




#endif