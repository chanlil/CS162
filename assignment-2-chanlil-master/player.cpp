/*********************************************************************
** Program Filename: player.cpp
** Author: Lilian Chan
** Date: 2/2/2019
** Description: This is the implementation file for the class player, 
which has a hand and books. 
** Input: N/A
** Output: N/A
*********************************************************************/

#include "player.hpp"
#include <iostream>

/*********************************************************************
** Function: player()
** Description: This is the constructor used to initialize the 
player's books and other features. 
** Parameters: N/A
** Pre-Conditions: Create a player object.
** Post-Conditions: Initializes player values.
*********************************************************************/ 

Player::Player(){
	books = new int[13];
	n_books = 0;
	hand = new Hand;
}
 
/*********************************************************************
** Function: ~player()
** Description: This is the destructor for the player class.
** Parameters: N/A
** Pre-Conditions: Have a player class. 
** Post-Conditions: Deletes books
*********************************************************************/ 

Player::~Player(){
	delete [] books;
	delete hand;
}

/*********************************************************************
** Function: show_hand
** Description: This shows the player's hand
** Parameters: N/A
** Pre-Conditions: Have a player with a hand
** Post-Conditions: Prints out hand
*********************************************************************/ 

int Player::show_hand(){
	hand->display_cards(); 
}

/*********************************************************************
** Function: check_for_book
** Description: This checks if a player has a book. then accordingly,
adjusts the book count and array. 
** Parameters: N/A
** Pre-Conditions: Have a player class
** Post-Conditions: Updates the number and arrya of books. 
*********************************************************************/ 

void Player::check_for_book(){
	hand->sort_cards();
	for(int i = 0; i < hand->get_n_cards() - 3; i++){
		//if (//hand->get_card(i).get_rank() == hand->get_card(i + 1).get_rank() 
		//	== hand->get_card(i + 2).get_rank() == hand->get_card(i + 4).get_rank()){
		if (hand -> get_card(i).get_rank() == hand -> get_card(i + 1).get_rank() &&
			hand -> get_card(i).get_rank() == hand -> get_card(i + 2).get_rank() &&
				hand -> get_card(i).get_rank() == hand -> get_card(i + 3).get_rank()){
				n_books++;
				books[n_books - 1] = hand->get_card(i).get_rank();
				hand->remove_card(i);
				hand->remove_card(i + 1);
				hand->remove_card(i + 2);
				hand->remove_card(i + 3);
		}		
	} 
}

/*********************************************************************
** Function: exchange_card
** Description: This is what happends when a player gives the other a card
** Parameters: Player other_pl, int asked_card
** Pre-Conditions: have a player class
** Post-Conditions: Exchnages cards between 2 hands
*********************************************************************/ 
//Change later
void Player::exchange_cards(Player *other_pl, int asked_card){  
	for(int i = 0; i < other_pl -> return_hand() -> get_n_cards(); i++){
		if (other_pl -> return_hand() -> get_card(i).get_rank() == asked_card){
			Card temp = other_pl -> return_hand() -> get_card(i);
			hand -> set_card(temp);
			other_pl -> return_hand() -> remove_card(i);			
			hand -> sort_cards();
		}
	}
}

/*********************************************************************
** Function: return_hand
** Description: This returns the hand
** Parameters: N/A
** Pre-Conditions: Have a player
** Post-Conditions: Returns the hand (EXACT; NOT A COPY)
*********************************************************************/ 

Hand* Player::return_hand(){
	//cout << "Returning hand" << endl;
	return hand;
}

/*********************************************************************
** Function: initialize_hand
** Description: This is where the player draws 7 cards
** Parameters: Deck* game_deck
** Pre-Conditions: Have a player and deck
** Post-Conditions: Initializes the hand
*********************************************************************/ 

void Player::initialize_hand(Deck* game_deck){
	for (int i = 0; i < 7; i++){
		hand -> set_card(game_deck -> draw_card());
	}
}

/*********************************************************************
** Function: go_fish
** Description: This allows the player to go fish and takes from the 
deck into their hand
** Parameters: N/A
** Pre-Conditions: Have a deck and player
** Post-Conditions: Moves card from deck to player. Also returns new
card rank.
*********************************************************************/ 

int Player::go_fish(Deck* game_deck){
	Card new_card = game_deck -> draw_card();
	hand -> set_card(new_card);
	return new_card.get_rank();
}

/*********************************************************************
** Function: set_n_books
** Description: This sets the n_books
** Parameters: int new_book
** Pre-Conditions: Have a player class
** Post-Conditions: Sets the n_books
********************************************************************/ 

void Player::set_n_books(int new_book){
	n_books = new_book;
}

/***********************************************************************
** Function: get_n_books
** Description: This returns the amount of books the player has 
** Parameters: N/A
** Pre-Conditions: Have a player object 
** Post-Conditions: Returns n_cards
***********************************************************************/ 

int Player::get_n_books(){
	return n_books;
}
