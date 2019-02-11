#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>'


int main(){

  struct gameState state;
  int s;
  int k[10] = {adventurer, council_room, village, great_hall, mine, cutpurse,
			gardens, feast, smithy, council_room};

  initializeGame(2, k, 100, &state);

  state.coins = 100;
  s = buyCard(adventurer, &state);
  assert(s == 0);
  
  state.numBuys = 5;
  state.coins = 0;
  s = buyCard(5, &state);
  assert(s == -1); 

  state.numBuys = 0;
  s = buyCard(5, &state);
  assert(s == -1);

  printf("buyCard test passed\n");
  return 0;
}
//Unit Test for buyCard
//Tests if has coins and a buy turn
//tests if not enough coins
//tests if enough coins and no buys