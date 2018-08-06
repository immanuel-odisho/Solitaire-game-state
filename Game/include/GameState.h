/*!	
*	\author Immanuel Odisho 400074199 odishoi
*	\date April/6/2018
*	\brief class for the game state of freecell 
*/
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "CardADT.h"
#include "DeckADT.h"
#include "Exceptions.h"


class GameState
{
public:
	/*!
	*	\brief this is a constructor for GameState
	*	\param deck the deck in the game
	*	\return GameState object
	*/
	GameState(DeckT deck);
	/*!
	*	\brief checks if card in tableau
	*	\param t the index of the tableau
	*	\param c card
	*	\return is card in the tableau?
	*/
	bool cardInTab(int t, CardT c);
	/*!
	*	\brief checks number of empty spots in the game
	*	\return number of empty free cells and tableau piles
	*/
	int numEmptySpots();
	/*!
	*	\brief moves a card in tableau to a free cell
	*	\param t index of tableau
	*	\param f index of freecell
	*/
	void TabtoFree(int t,int f);
	/*!
	*	\brief moves a card in tableau to a freecell
	*	\param t index of tableau
	*	\param f index of freecell
	*/
	void FreetoTab(int f, int t);
	/*!
	*	\brief moves a card in tableau to a foundation pile
	*	\param t index of tableau
	*	\param F index of foundation
	*/
	void TabtoFound(int t, int F);
	/*!
	*	\brief moves a card in free to a foundation pile
	*	\param f index of freecell
	*	\param F index of foundation
	*/
	void FreetoFound(int f, int F);
	/*!
	*	\brief moves a card in tableau to a tableau
	*	\param t index of tableau source
	*	\param T index of tableau destination
	*/
	void TabtoTab(int t, int T);
	/*!
	*	\param i index of freecell
	*	\return CardT in index 
	*/
	CardT getFreeCell(int i);
	/*!
	*	\param i index of tableau
	*	\return cards in tableau pile 
	*/
	std::vector<CardT> viewTab(int i);
	/*!
	*	\param i index of tableau
	*	\return top card in foundation pile
	*/
	CardT getTopFound(int i);
	/*!
	*	\param i index of tableau
	*	\return top card in tableau pile 
	*/
	CardT getTopTab(int i);
	/*!
	*	\return are there any valid moves remaining? 
	*/
	bool validMovesRem();
	/*!
	*	\return is the game won? 
	*/
	bool winCondition();
private:
	std::vector<CardT> cards;
	std::vector<std::vector<CardT> > tableaus = {{},{},{},{},{},{},{},{}};
	std::vector<std::vector<CardT> > freecells = {{},{},{},{}};
	std::vector<std::vector<CardT> > foundations = {{},{},{},{}};
	bool validMove(CardT a, CardT b);
	bool validMoveF(CardT a, CardT b);
	bool inOrder(std::vector<CardT> cards);

};



#endif