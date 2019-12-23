/*********************************************************************
** Program Filename: player.hpp
** Author: Lilian Chan
** Date: 2/2/2019 
** Description: This is the header file for the player class.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "hand.hpp"

class Player{
private: 
	Hand* hand;
	int* books;
	int n_books;
public:
	Player();
	~Player();
	int show_hand();
	void check_for_book();
	void exchange_cards(Player *, int); //CHANGE later
	Hand* return_hand();
	void initialize_hand(Deck *);
	int go_fish(Deck *);
	void set_n_books(int);
	int get_n_books();
};

#endif
