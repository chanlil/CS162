/*********************************************************************
** Program Filename: Sloth.cpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the implementation file for the sloth
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Sloth.hpp"

/*********************************************************************
** Function: Sloth(int age)
** Description: This is the parametrized constructor for sloth where 
the age can be specified
** Parameters: int age
** Pre-Conditions: Buy or create sloth 
** Post-Conditions: Fills in values
*********************************************************************/ 

Sloth::Sloth(int x){
	 age = x;
	 cost = 2000;
	 babies = 3;
 }

/*********************************************************************
** Function: Sloth()
** Description: This is the constructor for sloth 
** Parameters: N/A
** Pre-Conditions: Buy or create sloth 
** Post-Conditions: Fills in values
*********************************************************************/ 

Sloth::Sloth(){
	 age = 0;
	 cost = 2000;
	 babies = 3;
 }
