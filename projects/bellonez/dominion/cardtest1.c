#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>


/*
Smithy
	+3 Cards
*/

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

	printf("\n----------Testing Smithy Card----------\n");

	// copy the game state to a test case
	i=numHandCards(&state);
	cardEffect(smithy, choice1, choice2, choice3, &state, NULL);

	assert(numHandCards(&state) == i + 2);
    printf("Test passed\n");



	printf("----------End Testing Smithy Card----------\n");
}
