/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit test 5 for dominion-base
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

//int mineFunc(int choice1, int choice2, int i, int j, struct gameState *state, int currentPlayer, int handPos)
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
    int currentPlayer = 0;
    int handPos = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    memset(&G, 'z', sizeof(struct gameState));
    
    initializeGame(2, k, RANDOM_SEED, &G);

    int testReturn = mineFunc(1, 2, i, j, &G, currentPlayer, handPos);
    printf("Mine Function Returned: %d\n", testReturn);   

    
    if (testReturn == -1)
    {
        // If Mine Function Returns -1:
        assert(testReturn == -1);  
    }
    else if (testReturn == -110)
    {
        // If Mine Function Returns -110:
        // Function enters the IF statement inside the FOR loop and exits function early
        assert(testReturn == -110); 
    }
    else 
    {
        assert(testReturn == 0);    //Mine Function Returns 0 and function ran as expected
    }        
    
    return 0;
}

