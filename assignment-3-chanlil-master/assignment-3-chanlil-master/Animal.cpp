/*********************************************************************
** Program Filename: Animal.cpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the implementation file for the animal class
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Animal.hpp"

/*********************************************************************
** Function: Animal()
** Description: This is the constructor that initializes the age, 
cost, and the amount of babies.
** Parameters: N/A
** Pre-Conditions: Create an animal
** Post-Conditions: Initializes values for an animal
*********************************************************************/ 

Animal::Animal(){
	age = 0;
	cost = 0;
	babies = 0;	
}

/*********************************************************************
** Function: set_age
** Description: This sets the age
** Parameters: int x
** Pre-Conditions: Create or buy an animal or have a new day
** Post-Conditions: Sets the new age
*********************************************************************/ 

void Animal::set_age(int x){
	age = x;
}

/*********************************************************************
** Function: get_age
** Description: Returns the age of the animal
** Parameters: N/A
** Pre-Conditions: Getting the revenue for an animal, determining 
medical bills, etc.
** Post-Conditions: Returns the age
*********************************************************************/ 

int Animal::get_age(){
	return age;
}

/*********************************************************************
** Function: increment_age
** Description: This increments an animal's age
** Parameters: N/A
** Pre-Conditions: Have a new day
** Post-Conditions: Increases age
*********************************************************************/ 

void Animal::increment_age(){
	age++;
}

/*********************************************************************
** Function: set_cost
** Description: This sets the cost for an animal 
** Parameters: int x
** Pre-Conditions: Create an animal
** Post-Conditions: Sets the cost
*********************************************************************/ 

void Animal::set_cost(double x){
	cost = x;	
}

/*********************************************************************
** Function: get_cost
** Description: returns the cost
** Parameters: N/A
** Pre-Conditions: This happens when you want to buy food, get medical 
attention, or any cost-related factors
** Post-Conditions: Returns cost
*********************************************************************/ 

int Animal::get_cost(){
	return cost;
}

/*********************************************************************
** Function: set_babies
** Description: This sets the amount of babies an animal can have
** Parameters: int x
** Pre-Conditions: Create an animal
** Post-Conditions: Sets the babies they can have
*********************************************************************/ 

void Animal::set_babies(int x){
	babies = x;
}	

/*********************************************************************
** Function: get_babies
** Description: This returns the amount of babies the animal can have
** Parameters: N/A
** Pre-Conditions: Animal giving birth
** Post-Conditions: Returns amount of babies
*********************************************************************/ 

int Animal::get_babies(){
	return babies;	
}



