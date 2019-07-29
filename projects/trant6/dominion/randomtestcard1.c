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
    int result;
    int testPassed = 0;
    int testFailed = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    for (i = 0; i < 1000; i++)
    {
        numberPlayers = (rand() % 4) + 1;
        initializeGame(numberPlayers, k, RANDOM_SEED, &G);
        int randChoice = rand() % 2;
        int currentPlayer = rand() % numberPlayers;
        result = baronFunc(randChoice, &G, currentPlayer);

        if (result == -101)
        {
            // If Baron Function Returns -101:
            //then you found an estate card but function exits early right after the 1st while loop
            testFailed++;
        }
        else if (result == -102)
        {
            // If Baron Function Returns -102:
            // then you are in the first else conditional but exit the function early as well 
            testFailed++;
        }
        else
        {
            testPassed++;    //Baron Function Returns 0 and function ran as expected
        } 
    }
    printf("Baron Function\n"); 
    printf("# of Tests Passed: %d\n", testPassed); 
    printf("# of Tests Failed: %d\n", testFailed); 

    return 0;
    
}