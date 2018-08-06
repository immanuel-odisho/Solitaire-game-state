/*!	
*	\author Immanuel Odisho 400074199 odishoi
*	\date April/6/2018
*	\brief class that constructs a card object
*/
#ifndef CARDADT_H
#define CARDADT_H

#include "CardTypes.h"

class CardT
{
public:
	/*!
	*	\brief this is a constructor for CardT
	*	\param suit the suit of the card
	*	\param rank the rank of card
	*	\return CardT object
	*/
	CardT(RankT rank, SuitT suit);
	/*!
	*	\return rank of CardT object
	*/
	RankT getRank();
	/*!
	*	\return suit of CardT object
	*/
	SuitT getSuit();
	/*!
	*	\return rank of colour object
	*/
	ColourT getColour();
private:
	RankT rank;
	SuitT suit;
	ColourT colour;
	
};


#endif