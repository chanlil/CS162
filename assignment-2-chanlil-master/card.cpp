/*********************************************************************
** Program Filename: Card.cpp
** Author: Lilian Chan 
** Date: 2/1/2019
** Description: This is the implementation file for the card class,
which has rank and suit.
** Input: N/A
** Output: N/A
*********************************************************************/

#include "card.hpp"

using namespace std;

/*********************************************************************
** Function: card()
** Description: This is the constructor.
** Parameters: N/A 
** Pre-Conditions: Create a card  
** Post-Conditions: Sets default values for card
*********************************************************************/ 

Card::Card(){
	rank = 0;
	suit = 0;
}

/*********************************************************************
** Function: set_rank
** Description: This sets the rank variable
** Parameters: int r
** Pre-Conditions: Have a card object 
** Post-Conditions: Sets the card's rank
*********************************************************************/ 

void Card::set_rank(int r){
	rank = r;
}

/*********************************************************************
** Function:set_suit
** Description: This sets the suit variable
** Parameters: int s
** Pre-Conditions: Have a card object
** Post-Conditions: Set the card's suit
*********************************************************************/ 

void Card::set_suit(int s){
	suit = s;
}

/*********************************************************************
** Function: get_rank
** Description: ths returns the rank
**  Parameters: N/A
** Pre-Conditions: Create a card object
** Post-Conditions: Returns card rank
*********************************************************************/ 

int Card::get_rank(){
	return rank;
}

/*********************************************************************
** Function: get_suit
** Description: This returns the card's suit
** Parameters: Have a card object
** Pre-Conditions: Have a card object
** Post-Conditions: Returns card suit
*********************************************************************/ 

int Card::get_suit(){
	return suit;
}

/*********************************************************************
** Function: trans_rank
** Description: This translates the card rank into 1-9, J, Q, or K 
it is really called 
** Parameters: N/A
** Pre-Conditions: Make a card class
** Post-Conditions: prints out the rank in regular terms
*********************************************************************/ 

string Card::trans_rank(){
	int r = rank;
	
	if (r == 0)
		return "A";
	if (r == 1)
		return "2";
	if (r == 2)
		return "3";
	if (r == 3)	
		return "4";
	if (r == 4)
		return "5";
	if (r == 5)
		return "6";
	if (r == 6)
		return "7";
	if (r == 7)
		return "8";
	if (r == 8)
		return "9";
	if (r == 9)
		return "10";
	if (r == 10)
		return "J";
	if (r == 11)
		 return "Q";
	if (r == 12)
		 return "K";
}

/*********************************************************************
** Function: trans_suit
** Description: This translate the card's suit from an int to 
D, C, S, or H. 
** Parameters: N/A
** Pre-Conditions: Have a card class.
** Post-Conditions: Translates the card class into a letter. 
*********************************************************************/ 

string Card::trans_suit(){
	int s = suit;
		
	if (s == 0)
		return "D";
	if (s == 1)
		return "C";
	if (s == 2)
		return "H";
	if (s == 3)
		return "S";
}

