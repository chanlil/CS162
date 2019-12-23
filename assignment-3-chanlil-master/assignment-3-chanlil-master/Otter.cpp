/*********************************************************************
** Program Filename: Otter.cpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the implementation file for the otter
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Otter.hpp"

/*********************************************************************
** Function: Sloth(int age);
** Description: This is the parametrized constructor for sloth where 
the age can be specified
** Parameters: int age
** Pre-Conditions: Buy or create sloth 
** Post-Conditions: Fills in values
*********************************************************************/ 

Otter::Otter(int x){
	 age = x;
	 cost = 5000;
	 babies = 2;
 }

/*********************************************************************
** Function: Sloth();
** Description: This is the constructor for sloth 
** Parameters: N/A
** Pre-Conditions: Buy or create sloth 
** Post-Conditions: Fills in values
*********************************************************************/ 

Otter::Otter(){
	 age = 0;
	 cost = 5000;
	 babies = 2;
 }
