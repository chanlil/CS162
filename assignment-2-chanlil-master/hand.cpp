/*********************************************************************
** Program Filename: hand.cpp
** Author: Lilian Chan
** Date: 2/1/2019
** Description: This is the implementation file for the hands class,
which has a set of cards.
** Input: N/A
** Output: N/A
*********************************************************************/

#include <iostream>
#include "hand.hpp"
#include <stdio.h>
#include <stdlib.h> 
using namespace std;

/*********************************************************************
** Function: hand() 
** Description: This is the default constructor for a hand, which sets
up the array.  
** Parameters: N/A
** Pre-Conditions: Have a hand class amd deck class
** Post-Conditions: Initializes hand with card array. 
*********************************************************************/ 

Hand::Hand(){
	n_cards = 0;
	cards = new Card[1];                    //NEW THING I ADDED 
}

/*********************************************************************
** Function: ~hands()
** Description: This deletes the dynamically allocated card array.
** Parameters: N/A
** Pre-Conditions: Make a hand calss 
** Post-Conditions: Deletes array
*********************************************************************/ 

Hand::~Hand(){
	if (n_cards > 0){
		delete [] cards;
	}
}

/*********************************************************************
** Function: Hand(const Hand &other_hand)
** Description: This is the copy constructor for the hand
** Parameters: const Hand &other_hand
** Pre-Conditions: The value passed in cannot be corrupted
** Post-Conditions: The hand is copied
*********************************************************************/ 

Hand::Hand(const Hand &other_hand){
	this -> n_cards = other_hand.get_n_cards();
	this -> cards = new Card[other_hand.get_n_cards()];
	for (int i = 0; i < other_hand.get_n_cards(); i++){
			this -> cards[i] = other_hand.get_card(i); 
	}	
}

/*********************************************************************
** Function: display_cards
** Description: This displays all the cards in the player's hand. 
** Parameters: N/A
** Pre-Conditions: Have a hand object. 
** Post-Conditions: Prints out all the cards the player has.
*********************************************************************/ 

void Hand::display_cards(){
	cout << "This is your hand: " << endl;
	
	for (int i = 0; i < n_cards; i++){
		cout << i << ": "; 
		cout << cards[i].trans_suit();
		cout << cards[i].trans_rank() << "  "; 
	}

	cout << endl;
}

/*********************************************************************
** Function: get_n_cards
** Description: This returns the amount fo cards a hand has.  
** Parameters: N/A
** Pre-Conditions: Have a hand object.
** Post-Conditions: Prints out the hand.
*********************************************************************/ 

int Hand::get_n_cards() const{
	//cout << "Getting n cards" << endl;
	return n_cards; //Segfault
}

/*********************************************************************
** Function: sort_cards
** Description: This sorts the cards by rank
** Parameters: N/A
** Pre-Conditions: Have a hand object
** Post-Conditions: Cards sorted by rank 
*********************************************************************/ 

void Hand::sort_cards(){
	qsort(cards, n_cards, sizeof(Card), asc_ranks);
}

/*********************************************************************
** Function: asc_ranks
** Description: This sorts all the cards in ascending order by rank.
** Parameters: 2 Const card &
** Pre-Conditions: Have a hand object
** Post-Conditions: Sorts the array by rank
*********************************************************************/ 

int asc_ranks(const void  *c1, const void *c2){
	return (((Card*)c1) -> get_rank() < ((Card*)c2) -> get_rank());
}

/*********************************************************************
** Function: get_hand
** Description: This returns the hand
** Parameters: N/A
** Pre-Conditions: have a hand class
** Post-Conditions: returns the hand
*********************************************************************/ 

Card* Hand::get_hand(){
	return cards;
}

/*********************************************************************
** Function: set_card
** Description: This adds an extra card and expands the array
** Parameters: Card new_card
** Pre-Conditions: have a hand class
** Post-Conditions: adjusts the cards
*********************************************************************/ 

void Hand::set_card(Card new_card){
	cards = add_card();
	n_cards++;
	cards[n_cards - 1] = new_card;
	sort_cards();
}

/*********************************************************************
** Function: add_card
** Description: This adds a card to array
** Parameters: N/A
** Pre-Conditions: have a hand class
** Post-Conditions: adds a card to array
*********************************************************************/ 

Card* Hand::add_card(){
	Card* new_hand;
	new_hand = new Card[n_cards + 1];
	for (int i = 0; i < n_cards; i++){
		new_hand[i] = cards[i];
	}
	delete [] cards;
	return new_hand;	
}

/*********************************************************************
** Function: remove_card
** Description: this removes a card from the array
** Parameters: int num
** Pre-Conditions: Have a hand class
** Post-Conditions: Removes the card
*********************************************************************/ 

void Hand::remove_card(int remove){
	Card* new_hand = new Card[--n_cards];
	int count = 0;
	for (int i = 0; i < n_cards; i++){
		if (i != remove){
			new_hand[i] = cards[i];
			count++;
		} 
	}
 	delete [] cards;
	cards = new_hand;
}

/*********************************************************************
** Function: get_card
** Description: this returns the ith card
** Parameters: int i
** Pre-Conditions: have a hand
** Post-Conditions: returns the ith card
*********************************************************************/ 

Card Hand::get_card(int i) const{
	return cards[i];
}
