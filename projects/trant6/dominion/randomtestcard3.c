#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define RANDOM_SEED 20  //For RANDOM SEED 


int main()
{

    struct gameState G;
    int numberPlayers;
    int i;
    int j;
    int result;
    int testPassed = 0;
    int testFailed = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    for (i = 0; i < 1000; i++)
    {
        numberPlayers = (rand() % 4) + 1;
        int currentPlayer = rand() % numberPlayers;
        int nextPlayer = currentPlayer + 1;
        int tributeRevealedCards[2] = { -1, -1};        
        j = 0;
        
        initializeGame(numberPlayers, k, RANDOM_SEED, &G);

        result =  tributeFunc(j, &G, currentPlayer, nextPlayer, tributeRevealedCards);

        if (result == -107)
        {
        // If Tribute Function Returns -107:
        // After entering 2nd IF statement reveals the nextPlayers cards then exits function
            testFailed++;
        }
        else if (result == -108)
        {
        // If Tribute Function Returns -108:
        // Function enters the 3rd IF statement and after the desk is shuffled exits function early
            testFailed++;
        }
        else
        {
            testPassed++;    //Baron Function Returns 0 and function ran as expected
        } 
    }
    printf("Tribute Function\n"); 
    printf("# of Tests Passed: %d\n", testPassed); 
    printf("# of Tests Failed: %d\n", testFailed); 

    return 0;
    
}