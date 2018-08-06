#include "catch.h"
#include "CardADT.h"

TEST_CASE("tests for cardADT", "[CardT]"){

	CardT card1 = CardT(king,heart);
	CardT card2 = CardT(ace,spade);

	//tests if rank returned
	SECTION("return rank"){
		REQUIRE(card1.getRank() == 12);
		REQUIRE(card2.getRank() == 0);
	}


	//tests if suit returned
	SECTION("return suit"){
		REQUIRE(card1.getSuit() == 2);
		REQUIRE(card2.getSuit() == 3);
	}

	//tests if colour returned
	SECTION("return colour"){
		REQUIRE(card1.getColour() == 1);
		REQUIRE(card2.getColour() == 0);
	}

}