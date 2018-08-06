/*!	
*	\author Immanuel Odisho 400074199 odishoi
*	\date April/6/2018
*	\brief class that constructs a deck object
*/
#ifndef DECKADT_H
#define DECKADT_H

#include <vector>
#include "CardADT.h"
#include <stdlib.h>

class DeckT
{
public:
	/*!
	*	\brief this is a constructor for DeckT
	*	\return DeckT
	*/
	DeckT();
	/*!
	*
	*	\return cards in the deck object
	*/
	std::vector<CardT> getDeck();
	/*!
	*	\brief this shuffles a deck and returns the cards in random sequence
	*	\return random DeckT
	*/
	std::vector<CardT> getRandDeck();
	/*!
	*	\return size of deck
	*/
	int size();
private:
	std::vector<CardT> deck;
	SuitT suits[4] = {club,diamond,heart,spade};
	RankT ranks[13] = {ace,two,three,four,five,six,seven,eight,nine,ten,jack,queen,king}; 
};


#endif