/*********************************************************************
** Program Filename: deck.hpp
** Author: Lilian Chan
** Date: 2/1/2019
** Description: This is the header file for the deck class, which is 
made of an array of cards. 
** Input: N/A
** Output: N/A
*********************************************************************/
#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"
#include <time.h>
#include <stdlib.h>

class Deck { 
private:
	Card cards[52];
	int n_cards;
public:	
	Deck();
	Card draw_card();
	Card get_card(int);
	int get_n_cards();
	void set_n_cards(int);
	void shuffle();
};

#endif