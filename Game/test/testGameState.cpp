#include "catch.h"
#include "GameState.h"


TEST_CASE("tests for Game State", "[GameState]"){

	DeckT deck = DeckT();
	GameState game = GameState(deck);

	//tests if card in tableau
	SECTION("card in Tableau"){
		CardT ace_club = CardT(ace,club);
		CardT king_spade = CardT(king,spade);
		REQUIRE(true == game.cardInTab(0,ace_club));
		REQUIRE(false == game.cardInTab(1,ace_club));
		REQUIRE(false == game.cardInTab(3,ace_club));
		REQUIRE(false == game.cardInTab(4,ace_club));
		REQUIRE(false == game.cardInTab(5,ace_club));
		REQUIRE(false == game.cardInTab(6,ace_club));
		REQUIRE(true == game.cardInTab(7,king_spade));
	}

	//number of empty cells at beginning should be 4
	SECTION("number empty cells and/or Tableau piles"){
		REQUIRE(game.numEmptySpots() == 4);
	}

	//test if able to move tableau to freecell properly and getfreecell returns proper card
	//checks if able to move to then move more cards to occupied freecells
	SECTION("tableau to free move and check with getFreeCell"){
		game.TabtoFree(7,0);
		game.TabtoFree(0,1);
		game.TabtoFree(0,2);
		game.TabtoFree(0,3);
		CardT king_spade = game.getFreeCell(0);

		REQUIRE(king_spade.getRank() == 12);
		REQUIRE(king_spade.getSuit() == 3);
	
		//move to free cell when they are all full
		REQUIRE_THROWS_AS(game.TabtoFree(7,0),invalid_move);
		REQUIRE_THROWS_AS(game.TabtoFree(7,1),invalid_move);
		REQUIRE_THROWS_AS(game.TabtoFree(7,2),invalid_move);
		REQUIRE_THROWS_AS(game.TabtoFree(7,3),invalid_move);

	}

	//tests if getFreeCell throws error when empty free cell
	SECTION("getFreeCell when empty"){
		REQUIRE_THROWS_AS(game.getFreeCell(0),empty_cell);
	}

	//checks if returns the correct sequence of cards
	SECTION("viewing tableaus"){
		std::vector<CardT> temp = game.viewTab(7);

		REQUIRE(temp.back().getSuit() == 3);
		REQUIRE(temp.back().getRank() == 12);
	}

	//checks if can move frreecell to tableau, valid and invalid case
	SECTION("Freecell to Tableau move check"){
		game.TabtoFree(3,0);
		CardT two_heart = game.getFreeCell(0);

		REQUIRE(two_heart.getRank() == 1);
		REQUIRE(two_heart.getSuit() == 2);
		
		//move two heart to tableau 7 should not be valid since a king of spade lies there
		REQUIRE_THROWS_AS(game.FreetoTab(0,7),invalid_move);
	}

	//moves an ace to foundation adn then an invalid card
	SECTION("Tableau to foundation move"){
		//tableau 2 should be accepted since it has an ace at the end
		game.TabtoFound(1,0);
		//tableau 3 does not and should give invalid move
		REQUIRE_THROWS_AS(game.TabtoFound(2,0),invalid_move);
	}

	//moves a freecell to a foundation after moving from tableau
	SECTION("Tableau to Freecell then free to Foundation move"){
		
		game.TabtoFree(1,0);
		game.FreetoFound(0,1);
		
		game.TabtoFree(2,0);
		REQUIRE_THROWS_AS(game.FreetoFound(0,1),invalid_move);
	}

	//moves a tableau to tableau and expects invalid case
	SECTION("Tableau to Tableau move"){
		
		REQUIRE_THROWS_AS(game.TabtoTab(7,1), invalid_move);
	}

	//checks if proper top card card of foundation returned
	SECTION("get top card of foundation"){
		REQUIRE_THROWS_AS(game.getTopFound(0),empty_cell);
		game.TabtoFound(1,0);
		CardT ace_diamond = game.getTopFound(0);
		REQUIRE(ace_diamond.getRank() == 0);
		REQUIRE(ace_diamond.getSuit() == 1);
	}

	//checks if proper top card card of tableau returned
	SECTION("get top of tableau 7"){
		CardT king_spade = game.getTopTab(7);

		REQUIRE(king_spade.getRank() == 12);
		REQUIRE(king_spade.getSuit() == 3);
		REQUIRE(king_spade.getColour() == 0);
	}

	//checks if valid moves remain when they should at beginning of game
	SECTION("check if valid moves remain"){
		
		REQUIRE(game.validMovesRem() == true);

	}

	//checks if game is on at beginning but it should not be - false
	SECTION("detect for winning condition"){
		
		REQUIRE(game.winCondition() == false);


	}
}