/*********************************************************************
** Program Filename: gold.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the gold header file
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef GOLD_HPP
#define GOLD_HPP
#include "Event.hpp"
#include <string>

using namespace std;

class Gold : public Event{
	public:
		Gold();
		string percept();
		int encounter();
};
	
#endif
