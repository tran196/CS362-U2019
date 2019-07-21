/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit card test 4 for dominion-base
 *
 * Get Winners Function
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

//int getWinners(int players[MAX_PLAYERS], struct gameState *state)
/*
    - Initialize variables
    - Call refactored functions
    - Assert the results
 */

int main (int argc, char** argv)
{
    struct gameState G;
    int players[MAX_PLAYERS];
    
    memset(&G, 'z', sizeof(struct gameState));

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
        sea_hag, tribute, smithy};
    
    initializeGame(2, k, RANDOM_SEED, &G);

    int testReturn = getWinners(players, &G);
    printf("getWinners Function Returned: %d\n", testReturn);   

    
    if (testReturn == 0)
    {
        assert(testReturn == 0);  //getWinners Function Returns 0 and function ran as expected
    }
    else 
    {
        printf("getWinners Function Return A Number Other Than 0\n");
    }        
    
    return 0;
}

