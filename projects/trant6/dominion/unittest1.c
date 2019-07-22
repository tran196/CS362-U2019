/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit test 1 for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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

//int baronFunc (int choice1, struct gameState *state, int currentPlayer)
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
    
    initializeGame(2, k, RANDOM_SEED, &G);

    int currentPlayer = 0;
    int testReturn = baronFunc(1, &G, currentPlayer);

    printf("Baron Function Returned: %d\n", testReturn);    

    if (testReturn == -101)
    {
        // If Baron Function Returns -101:
        //then you found an estate card but function exits early right after the 1st while loop
        assert(testReturn = -101);
    }
    else if (testReturn == -102)
    {
        // If Baron Function Returns -102:
        // then you are in the first else conditional but exit the function early as well 
        assert(testReturn = -102);
    }
    else
    {
        assert(testReturn == 0);    //Baron Function Returns 0 and function ran as expected
    } 
    
    return 0;
}

