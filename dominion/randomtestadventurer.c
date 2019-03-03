#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	struct gameState G;
	int result, rand = 0, player = 1, passed = 0, failed =0;
	int handCount, deckCount; 
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			gold, tribute, smithy};
	
	printf("Beginning Running Random Test Card for adventurer.\n");
	for(int j = 0; j < 4; j++){
		for(int i = 0; i < 500; i++){
			int numPlayers = rand() % 4;
			int gameSeed = rand() % 5000;
					
			initializeGame(numPlayers, k, gameSeed, &G);
			
			rand = rand() % 10;
			if(rand == 5){
				G.deckCount[player] = 0;
				deckCount = 0;
			}
			else{
				rand = rand() % MAX_DECK;
				G.deckCount[player] = rand;
				deckCount = rand;
			}
			
			rand = rand() % MAX_DECK;
			G.handCount[player] = rand() % MAX_HAND;
			handCount = rand;
			
			G.discardCount[player] = rand() % MAX_DECK;
			
			result = cardEffect(adventurer, 1, 1, 1, &G);
			if(result == 0){
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