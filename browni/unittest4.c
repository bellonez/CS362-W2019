#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"
#include <time.h>



int main(){
  
  int turn = 0;
  int test = 0;
  struct gameState state;

  for (int i = 0; i < 15; i++){
    state.whoseTurn = turn;
    test = whoseTurn(&state);

    assert(test == turn);

    turn++;
  }
  printf("Test passed\n");
  return 0;
}

//Unit Test for whoseTurn()
// tests whose turn it is an dpasses if turn state is correct
