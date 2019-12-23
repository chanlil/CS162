/*********************************************************************
** Program Filename: card.hpp 
** Author: Lilian Chan
** Date: 2/1/2019
** Description: This is the header file for the card class.
** Input: N/A 
** Output: N/A
*********************************************************************/

#ifndef CARD_HPP
#define CARD_HPP
#include <string>

using namespace std;

class Card {
private:
	int rank;
	int suit;
public:
	Card();
	void set_rank(int r);
	void set_suit(int c);
	int get_rank();
	int get_suit();
	string trans_rank();
	string trans_suit();
};

#endif
