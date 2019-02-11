#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>




int main(){

  assert(getCost(curse) == 0);

  assert(getCost(adventurer) == 6);

  assert(getCost(village) == 3);

  assert(getCost(mine) == 5);

  assert(getCost(feast) == 4);
  
  assert(getCost(great_hall) == 3);
  
  assert(getCost(tribute) == 5);
  
  assert(getCost(copper) == 0);
  
  assert(getCost(silver) == 3);
  
  assert(getCost(gold) == 6);

  return 0;
}

//Unit Test for getCost
//checks card costs.  I only chose a few due to time limitations. 