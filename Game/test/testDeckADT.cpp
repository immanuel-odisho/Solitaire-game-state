#include "catch.h"
#include "DeckADT.h"

TEST_CASE("tests for DeckADT", "[DeckT]"){

	DeckT deck = DeckT();

	//tests if correct size
	SECTION("size"){

		REQUIRE(deck.size() == 52);
	}
	//checks if the deck is in the correct and expected order
	SECTION("deck correct order"){
		int i = 0;
		for (; i < 13; i++) {
			REQUIRE(deck.getDeck()[i].getSuit() == 0);
			REQUIRE(deck.getDeck()[i].getRank() == i);
		}

		i = 0;
		for (; i < 13; i++) {
			REQUIRE(deck.getDeck()[i + 13].getSuit() == 1);
			REQUIRE(deck.getDeck()[i + 13].getRank() == i);
		}

		i = 0;
		for (; i < 13; i++) {
			REQUIRE(deck.getDeck()[i + 26].getSuit() == 2);
			REQUIRE(deck.getDeck()[i + 26].getRank() == i);
		}

		i = 0;
		for (; i < 13; i++) {
			REQUIRE(deck.getDeck()[i + 39].getSuit() == 3);
			REQUIRE(deck.getDeck()[i + 39].getRank() == i);
		}

	}
}