/*********************************************************************
** Program Filename: hand.hpp
** Author: Lilian Chan
** Date: 2/1/2019
** Description: This is the header file for the hand class.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef HAND_HPP
#define HAND_HPP

#include "deck.hpp"

class Hand{
private:	
	Card* cards;
	int n_cards;
public:
	Hand(); 
	~Hand();
	Hand(const Hand &);
	void display_cards();
	int get_n_cards() const;
	void sort_cards();
	//int asc_ranks(const void *, const void *);
	Card* get_hand();
	void set_card(Card);
	Card* add_card();
	void remove_card(int);
	Card get_card(int) const;
};

/*********************************************************************
** Function: asc_ranks
** Description: This sorts in ascending order by rank
** Parameters: 2 const void*
** Pre-Conditions: When the organizing hand function is called
** Post-Conditions: This organizes the hand by rank
*********************************************************************/ 

int asc_ranks(const void*, const void*);

#endif
