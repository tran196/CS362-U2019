/* -----------------------------------------------------------------------
 * Author: Tuan Tran
 * Date: 7/17/19
 * CS362
 * Assignment 3 Unit Tests
 * Unit test 4 for dominion-base
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

//int tributeFunc(int i, struct gameState *state, int currentPlayer, int nextPlayer, int *tributeRevealedCards)
/*
    - Initialize variables
    - Call refactored functions
    - Assert the results
 */

int main (int argc, char** argv)
{
    struct gameState G;
    
    int i = 0;
    int currentPlayer = 0;
    int nextPlayer = currentPlayer + 1;
    int tributeRevealedCards[2] = { -1, -1};
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    memset(&G, 'z', sizeof(struct gameState));
    
    initializeGame(2, k, RANDOM_SEED, &G);

    int testReturn = tributeFunc(i, &G, currentPlayer, nextPlayer, tributeRevealedCards);
    printf("Tribute Function Returned: %d\n", testReturn);   

    
    if (testReturn == -107)
    {
        // If Tribute Function Returns -107:
        // After entering 2nd IF statement reveals the nextPlayers cards then exits function
        assert(testReturn == -107);  
    }
    else if (testReturn == -108)
    {
        // If Tribute Function Returns -108:
        // Function enters the 3rd IF statement and after the desk is shuffled exits function early
        assert(testReturn == -108); 
    }
    else 
    {
        assert(testReturn == 0);    //Tribute Function Returns 0 and function ran as expected
    }        
    
    return 0;
}

