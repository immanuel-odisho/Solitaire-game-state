#include "CardADT.h"
#include "DeckADT.h"
#include "GameState.h"


GameState::GameState(DeckT deck){
	if (deck.size() != 52) {throw wrong_size_deck();}
	cards = deck.getDeck();
	
	int i = 0;
	for (; i < 7; i++) {tableaus[0].push_back(cards[i]);}
	for (; i < 14; i++) {tableaus[1].push_back(cards[i]);}
	for (; i < 21; i++) {tableaus[2].push_back(cards[i]);}
	for (; i < 28; i++) {tableaus[3].push_back(cards[i]);}
	for (; i < 34; i++) {tableaus[4].push_back(cards[i]);}
	for (; i < 40; i++) {tableaus[5].push_back(cards[i]);}
	for (; i < 46; i++) {tableaus[6].push_back(cards[i]);}
	for (; i < 52; i++) {tableaus[7].push_back(cards[i]);}


}

bool GameState::cardInTab(int t, CardT c){
	
	if (!((t >= 0) && (t <= 7))) {throw invalid_argument();}


	for (int j = 0; j < tableaus[t].size(); j++) {
		if ((c.getRank() == tableaus[t][j].getRank()) && (c.getSuit() == tableaus[t][j].getSuit())) {return true;}
	}

	return false;

}

int GameState::numEmptySpots(){

	int sum = 0;

	for (int i = 0 ; i <  tableaus.size(); i++){
		if (tableaus[i].size() == 0) sum++;
	}

	for (int i = 0 ; i <  freecells.size(); i++){
		if (freecells[i].size() == 0) sum++;
	}



	return sum;

}

void GameState::TabtoFree(int t, int f){
	if (!((t >= 0) && (t <= 7) && (f >= 0) && (f <=3))) {throw invalid_argument();}
	if (!(freecells[f].empty())) {throw invalid_move();}


	if (tableaus[t].empty()) {throw invalid_move();}

	
		CardT c = tableaus[t].back();
		tableaus[t].pop_back();
		freecells[f].push_back(c);
}

CardT GameState::getFreeCell(int i){

	if (freecells[i].empty()) {throw empty_cell();}
	//if free cell empty return empty cell exception
	//add invalid argument 
	return freecells[i][0];
}

std::vector<CardT> GameState::viewTab(int i){
	if (!((i >= 0) && (i <= 7))) {throw invalid_argument();}
	if (tableaus[i].empty()) {throw empty_cell();}
	return tableaus[i];
}

void GameState::FreetoTab(int f, int t){
	if (!((f >= 0) && (f <= 3) && (t >= 0) && (t <= 7))) {throw invalid_argument();}
	//if free not empty 
	if (freecells[f].empty()) {throw invalid_move();}
	//if tabluea empty go ahead


	if (tableaus[t].empty()) {
		CardT c = freecells[f].back();
		freecells[f].pop_back();
		tableaus[t].push_back(c);
	}

	else {
		if (validMove(freecells[f].back(),tableaus[t].back())){
		CardT c = freecells[f].back();
		freecells[f].pop_back();
		tableaus[t].push_back(c);
		}else {throw invalid_move();}

	}
}




bool GameState::validMove(CardT a, CardT b){

	return ((a.getColour() != b.getColour()) && (b.getRank() + 1 == a.getRank())) ;


}

void GameState::TabtoFound(int t, int F){
	if (!((t >= 0) && (t <= 7) && (F >= 0) && (F <=3))) {throw invalid_argument();}
	if (tableaus[t].size() != 0){
		//add invalid argument 
	if (foundations[F].size() == 0){
		if (tableaus[t].back().getRank() == 0) {
			CardT c = tableaus[t].back();
			tableaus[t].pop_back();
			foundations[F].push_back(c);
		}else {throw invalid_move();}
		//else invalid move exception

	}else{
		if (validMoveF(tableaus[t].back(),foundations[F].back())) {
			CardT c = tableaus[t].back();
			tableaus[t].pop_back();
			foundations[F].push_back(c);
		}else {throw invalid_move();}
	} 
}

}


bool GameState::validMoveF(CardT a, CardT b){

	return ((a.getSuit() == b.getSuit()) && (b.getRank() == a.getRank() + 1)) ; 
}

void GameState::FreetoFound(int f, int F){
	if (!((f >= 0) && (f <= 3) && (F >= 0) && (F <=3))) {throw invalid_argument();}

	if (freecells[f].size() != 0){
	
	if (foundations[F].size() == 0){
		if (freecells[f].back().getRank() == 0) {
			CardT c = freecells[f].back();
			freecells[f].pop_back();
			foundations[F].push_back(c);
		}else {throw invalid_move();}
		//else invalid move exception

	}else {
		if (validMoveF(freecells[f].back(),foundations[F].back())) {
			CardT c = freecells[f].back();
			freecells[f].pop_back();
			foundations[F].push_back(c);
		}
		else {throw invalid_move();}
	} 
}
}


void GameState::TabtoTab(int t, int T){
	if (!((t >= 0) && (t <= 7) && (T >= 0) && (T <=3))) {throw invalid_argument();}
	//if t is not empty -> invalid move/empty cell
	if (tableaus[t].empty()) {throw invalid_move();}
	//add invalid argument and invalid move instead empty
	if (tableaus[T].empty()) {
		CardT c = tableaus[t].back();
		tableaus[t].pop_back();
		tableaus[T].push_back(c);
	}if (validMove(tableaus[t].back(),tableaus[T].back())){
		CardT c = tableaus[t].back();
		tableaus[t].pop_back();
		tableaus[T].push_back(c);
	}else {throw invalid_move();}

}

CardT GameState::getTopFound(int i){
	if (!((i >= 0) && (i <= 3))) {throw invalid_argument();}
	if (foundations[i].empty()) {throw empty_cell();}

	return foundations[i].back();
}

CardT GameState::getTopTab(int i){
	if (!((i >= 0) && (i <= 7))) {throw invalid_argument();}
	if (tableaus[i].empty()) {throw empty_cell();}
	return tableaus[i].back();	
}

bool GameState::winCondition(){

	bool check = true;

	for (int i = 0; i < foundations.size(); i++){
		check = check && inOrder(foundations[i]);
	}

	return check;
}

bool GameState::validMovesRem(){
	if (this->numEmptySpots() > 0) return true;

	for (int i = 0 ; i < foundations.size(); i++){
		if (foundations[i].size() == 0){
			for (int j = 0; j < tableaus.size(); j++) {
				if (tableaus[j].back().getRank() == 0) return true;
			}
		}else {
			for (int j = 0; j < tableaus.size(); j++) {
				if (validMoveF(tableaus[j].back(),foundations[i].back())) return true;
			}
		}
	}

	for (int i = 0; i < freecells.size(); i++){
		for (int j = 0; j < tableaus.size(); j++){
			if (validMove(freecells[i].back(), tableaus[j].back())) return true;
		}

	}


	for (int i = 0; i < foundations.size(); i++){
		if (foundations[i].size() == 0){
			for (int j = 0; j < freecells.size(); j++) {
				if (freecells[j].back().getRank() == 0) return true;
			}
		}else{
			for (int j = 0; j < freecells.size(); j++) {
				if (validMoveF(freecells[j].back(),foundations[i].back())) return true;
			}
		}


	}
	
	return false;		
}



	



bool GameState::inOrder(std::vector<CardT> cards){

	bool check = true;
	if (cards.size() != 13) {return false;}
	for (int i = 0; i < cards.size() - 1; i++){
		check = check && ((cards[i].getRank() < cards[i + 1].getRank()) && (cards[i].getSuit() == cards[i + 1].getSuit()));
	}

	return check;
}