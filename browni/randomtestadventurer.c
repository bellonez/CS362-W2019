#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	struct gameState G;
	int random = 0, player = 1, passed = 0, failed =0;
	int handCount, deckCount; 
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			gold, tribute, smithy};
	
	printf("Beginning Running Random Test Card for adventurer.\n");
	for(int j = 0; j < 4; j++){
		for(int i = 0; i < 500; i++){
			int numPlayers = rand() % 4;
			int gameSeed = rand() % 5000;
					
			initializeGame(numPlayers, k, gameSeed, &G);
			
			random = rand() % 10;
			if(random == 5){
				G.deckCount[player] = 0;
				deckCount = 0;
			}
			else{
				random = rand() % MAX_DECK;
				G.deckCount[player] = random;
				deckCount = random;
			}
			
			random = rand() % MAX_DECK;
			G.handCount[player] = rand() % MAX_HAND;
			handCount = random;
			
			G.discardCount[player] = rand() % MAX_DECK;
			
			if (adventurerCardEffect(&G, 1, 1)==0){
				passed++;
			}
			else{
				failed++;
			}
		}
	}
	printf("# of Tests Passed: %d\n", passed);
    printf("# of Cards Drawn To Hand Failed: %d\n", failed);
}
