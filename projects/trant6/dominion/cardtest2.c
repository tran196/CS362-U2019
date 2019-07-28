/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit card test 2 for dominion-base
 *
 * Shuffle Function
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

//int shuffle(int player, struct gameState *state) 
/*
    - Initialize variables
    - Call refactored functions
    - Assert the results
 */

int main (int argc, char** argv)
{
    struct gameState G;
    int currentPlayer = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    memset(&G, 'z', sizeof(struct gameState));
    
    initializeGame(2, k, RANDOM_SEED, &G);

    int testReturn = shuffle(currentPlayer, &G);
    printf("shuffle Function Returned: %d\n", testReturn);   

    
    if (testReturn == -1)
    {
        assert(testReturn == -1);  
    }
    else 
    {
        assert(testReturn == 0);    //Shuffle Function Returns 0 and function ran as expected
    }        
    
    return 0;
}

