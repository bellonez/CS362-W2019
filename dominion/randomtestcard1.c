/* 1. Should gain 3 cards from deck to player's hand
 * 2. Test hand size after playing smithy
 * 3. Test deck size after playing smithy
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main() {
	
    struct gameState G;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};  
    int dSize, hSize;
    int handPos;
    int deckBefore;
    int deckAfter;
    int handBefore;
    int handAfter;
    int preDiscard;
    int postDiscard;
    int i;
    int failDeck = 0;
    int failHand = 0;
    int discardFailure = 0;
    int testPassed = 0;
    int passed;
    
    srand(time(NULL));
    for(i = 0; i < 1000; i++){
        initializeGame(numPlayers, k, seed, &G);
        dSize = rand() % (MAX_DECK + 1);
	    hSize = rand() % (dSize + 1);
            
        G.deckCount[0] = dSize - hSize;
        G.handCount[0] = hSize;
        
        handPos = G.hand[curPlayer][G.handCount[curPlayer] - 1];
        deckBefore = G.deckCount[0];
        handBefore = G.handCount[0];
        preDiscard = G.playedCardCount;
              
        smithyEffect(handPos, curPlayer, &G);
        
        deckAfter = G.deckCount[0];
        handAfter = G.handCount[0];
        postDiscard = G.playedCardCount;
         
        passed = 1;
        
         if(deckAfter != (deckBefore - 3)){
            printf("Wrong number of cards drawn: Fail\n");
            failDeck++;
            passed = 0;
        }
		
		if(handAfter != (handBefore + 2)){
            printf("Wrong amount of cards drawn: Fail\n");
            failHand++;
            passed = 0;
        }
        
        if(postDiscard != (preDiscard + 1)){
            printf("Not Discarded after use: Fail\n");
            discardFailure++;
            passed = 0;
        }
        
        if(passed == 1){
            printf("All Tests Passed!!\n");
            testPassed++;
        }
        
    }
     
   printf("\n\n");
   printf("# of Tests Passed: %d\n", testPassed);
   printf("# of Cards Drawn To Hand Failed: %d\n", failHand);
   printf("# of Smithy Discarded Fails: %d\n\n", discardFailure);        
   
   return 0;
}