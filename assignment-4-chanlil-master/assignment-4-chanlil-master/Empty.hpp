/*********************************************************************
** Program Filename: empty.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the empty header file
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "Event.hpp"
#include <string>

using namespace std;

class Empty : public Event{
	public:
		Empty();
		string percept();
		int encounter();
};
	
#endif
