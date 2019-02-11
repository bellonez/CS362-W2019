#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Adventurer:
draw until 2 treasurers revealed
discard non-treasurers drawn
*/


// runs the tests
int main () {
    
    int i;
   	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	struct gameState state;
	int k[10] = {adventurer, council_room, village, great_hall, mine, cutpurse,
			gardens, feast, smithy, council_room};
    

	// initialize a game state and player cards
	initializeGame(2, k, 100, &state);

	printf("\n----------Testing Adventurer Card----------\n");

	assert(cardEffect(adventurer, choice1, choice2, choice3, &state, 0, NULL) == 0);
	printf("Test Passed\n");
		
	
	printf("----------End Testing Adventurer Card----------\n");
}

