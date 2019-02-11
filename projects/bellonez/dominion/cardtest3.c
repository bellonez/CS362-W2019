#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/*
Village:
    +1 Card
    +2 Actions
*/

int main()
{
    int i;
    int act;
	int count;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	struct gameState state;

	int k[10] = {adventurer, council_room, village, great_hall, mine, cutpurse,
			gardens, feast, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(2, k, 100, &state);

	printf("\n----------Testing Village Card----------\n");

	act=state.numActions;
	i=cardEffect(village, choice1, choice2, choice3, &state,0, NULL);
	count = numHandCards(&state);

	assert(state.numActions == act +2);

	assert(i==0);

	assert(numHandCards(&state) = count+1);

	printf("Test passed\n");
	printf("----------End Testing Village Card----------\n");
	return 0;
}
