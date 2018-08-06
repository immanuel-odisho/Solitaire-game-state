#include "../include/CardADT.h"
#include "../include/CardTypes.h"

CardT::CardT(RankT rank, SuitT suit){
	this->rank = rank;
	this->suit = suit;

	if (suit == spade || suit == club) {this->colour = black;}
	else {this->colour = red;}
}


RankT CardT::getRank() {return this->rank;}

SuitT CardT::getSuit() {return this->suit;}

ColourT CardT::getColour() {return this->colour;}