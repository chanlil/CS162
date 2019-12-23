/*********************************************************************
** Program Filename: Monkey.hpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the header file for the monkey class
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef MONKEY_HPP
#define MONKEY_HPP
#include "Animal.hpp"

class Monkey: public Animal{
	public:
		Monkey(int x);
		Monkey();
		double bonus();
};

#endif