#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"
#include "assert.h"
#include <time.h>

int main(){
    
    
    int numTest=5000;
    
    int gameStateCreated=0;
    int failed=0;
    int passed=0;
    int actionsSame=0;
    int actionsDifferent=0;
    int handDecreased=0;
    int handEqual=0;
    

    struct gameState G;
    struct gameState S;
    
    
    for (int z=0; z < numTest; z++){
	int preAct=G.numActions;
	int postAct;
    int handCount1=G.handCount[1];
    int handCount2;
    int result;
    result= cardEffect(great_hall, 0, 0, 0, &G, 10, 0);
    S=G;    
    int returnValue;
    struct gameState G;
    int players=2;
    n=1000;
    k=1;
    int randomSeed = rand() % (n + 1) + l;
    int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
       
    returnValue=initializeGame(players,k,randomSeed, &G);
    
    if(returnValue == 0)
    {
    gameStateCreated++;
    }    
      
    if(result==0){
            passed++;
    }
            
    if(result!=0){
        failed++;
    }    
    if(preAct!=postAct){
       actionsDifferent++;
     }    
            
    postAct=S.numActions;
    if(preAct==postAct){
       actionsSame++;
    }
        
     
    handCount2=S.handCount[1];
    if(handCount2<=handCount1){
       handEqual++;
    }
        
    if(handCount2>handCount1){
      handDecreased++;
    }    
            
}
    
    printf("Random Card Test 2:\n");
    printf("Great Hall:\n");
    printf("The Test was run %d times\n", numTest);
    printf("Card was successfully run:  %d\n", passed);
    printf("Fail: Card was unsuccessfully run:  %d\n", failed);
    printf("The Number of actionst is same:  %d\n", actionsSame);
    printf("Fail: Number of actions different:  %d\n", actionsDifferent);
    printf("The draw is correct: %d\n" , handEqual);
    printf("Fail: Thedraw is incorrect: %d\n" , handDecreased);

    return 0;
}