/*********************************************************************
** Program Filename: Animal.hpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is header class for the parent class for all the 
animals
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal{
	protected:
		int age;
		double cost;
		int babies;	
	public:
		Animal();
		void set_age(int);
		int get_age();
		void increment_age();
		void set_cost(double);
		int get_cost();	
		void set_babies(int);
		int get_babies();
};

#endif