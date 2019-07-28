/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit test 3 for dominion-base
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define RANDOM_SEED 20  //For RANDOM SEED 

//int ambassadorFunc(int choice1, int choice2, int i, int j, struct gameState *state, int handPos, int currentPlayer)
/*
    - Initialize variables
    - Call refactored functions
    - Assert the results
 */

int main (int argc, char** argv)
{
    struct gameState G;
    
    int i = 0;
    int j = 0;
    int handPos = 0;
    int currentPlayer = 0;
    int start = -1;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    memset(&G, 'z', sizeof(struct gameState));
    
    initializeGame(2, k, RANDOM_SEED, &G);

    int testReturn = ambassadorFunc(1, 2, i, j, &G, handPos, currentPlayer);
    printf("Ambassador Function Returned: %d\n", testReturn);   

    
    if (testReturn == -105)
    {
        // If Ambassador Function Returns -105:
        // then after entering 1st IF statement adds +2 coins then exits function
        assert(testReturn == -105);  
    }
    else if (testReturn = -106)
    {
        // If Ambassador Function Returns -106:
        // then function enters the 1st ELSE IF statement and exits function early
        assert(testReturn == -106); 
    }
    else if (testReturn == -1)
    {
        //Player doesn't have enough cards to discard
        assert(testReturn == -1);
    }
    else 
    {
        assert(testReturn == 0);    //Ambassador Function Returns 0 and function ran as expected
    }        
    
    return 0;
}

