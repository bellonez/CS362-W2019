#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/*
Great Hall:
	+1 Card
	+1 Actions
	discard card from hand
*/

void main() 
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

	printf("\n----------Testing Great Hall Card----------\n");
	
	act=state.numActions;
	i=cardEffect(great_hall, choice1, choice2, choice3, &state, NULL);
	count = numHandCards(&state);
	assert(state.numActions == act +1);
	assert(i==0);
	assert(numHandCards(&state)=count+1);
	printf("Passed tests\n");
	
	printf("----------End Testing Great Hall Card----------\n");
}