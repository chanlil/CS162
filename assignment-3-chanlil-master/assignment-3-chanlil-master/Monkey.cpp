/*********************************************************************
** Program Filename: Monkey.cpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the implementation file for the monkey
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Monkey.hpp"
#include <cstdlib>
#include <ctime>
#include <stdio.h> 

/*********************************************************************
** Function: Monkey(int age);
** Description: This is the parametrized constructor for monkey where 
the age can be specified
** Parameters: int age
** Pre-Conditions: Buy or create monkey
** Post-Conditions: Fills in values
*********************************************************************/ 

 Monkey::Monkey(int x){
	 age = x;
	 cost = 15000;
	 babies = 1;
 }

/*********************************************************************
** Function: Monkey();
** Description: This is the constructor for monkey 
** Parameters: N/A
** Pre-Conditions: Buy or create monkey
** Post-Conditions: Fills in values
*********************************************************************/ 

 Monkey::Monkey(){
	 age = 0;
	 cost = 15000;
	 babies = 1;
 }

/*********************************************************************
** Function: bonus()
** Description: This is where it gives back the bonus for busy days
** Parameters: N/A
** Pre-Conditions: Have a busy day
** Post-Conditions: Returns bonuses
*********************************************************************/ 

double bonus(){
	srand(time(NULL)); 
	double bonus = rand()%(500 - 250 + 1) + 250;
	return bonus;
}