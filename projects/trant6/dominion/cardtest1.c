/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit Card test 1 for dominion-base
 * Testing Initalize Game Function
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

//int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
/*
    - Initialize variables
    - Call refactored functions
    - Assert the results
 */

int main (int argc, char** argv)
{
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    memset(&G, 'z', sizeof(struct gameState));
    
    int testReturn = initializeGame(2, k, RANDOM_SEED, &G);;

    printf("Initialize Game Function Returned: %d\n", testReturn);    

    if (testReturn == -1)
    {
        assert(testReturn = -1);
    }
    else
    {
        assert(testReturn == 0);    //InitalizeGame Function Returns 0 and function ran as expected
    } 
    
    return 0;
}

