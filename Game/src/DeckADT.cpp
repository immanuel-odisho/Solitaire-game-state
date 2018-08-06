#include "DeckADT.h"
#include <stdlib.h>
#include <time.h>

DeckT::DeckT(){
	for (SuitT s : suits){
		for (RankT r : ranks){
			CardT c = CardT(r,s);
			deck.push_back(c);
		}
	}
}

std::vector<CardT> DeckT::getDeck() {return this->deck;}

std::vector<CardT> DeckT::getRandDeck() {
	
	std::vector<CardT> temp;
	int x,y;
	srand (time(NULL));

	for (CardT c : deck){
		temp.push_back(c);
	}

	for (int i = 0; i < 100; i++){

		x = rand() % 52;
		y = rand() % 52;
		CardT Swapper = temp[x];
		temp[x] = temp[y];
		temp[y] = Swapper;
	}

	return temp;
}

int DeckT::size(){
	return deck.size();
}

// CardT DeckT::getCard(int i) {return deck[i];}

