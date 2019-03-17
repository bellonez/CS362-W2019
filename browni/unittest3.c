#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    

    int k[10] = {adventurer, council_room, village, great_hall, mine, cutpurse,
			gardens, feast, smithy, council_room};
    struct gameState state;
    int initGame;
    initGame = initializeGame(2, k, 100,  &state);
    int i;
    
    for (i = 10; i >= 0; i--)
    {
        state.supplyCount[province] = i;
        if (i > 0)
        {
            printf("Expected Game should not be over: 0 Actual: %i\n", isGameOver(&state));
        }
        else
        {
            printf("Expected game should be over: 1 Actual: %i\n", isGameOver(&state));
        }
    }
    
    printf("PASS!\n");
 
    return 0;
    
}
//unit test for isGameOver()
//compares supply count to game state to test nd condition.