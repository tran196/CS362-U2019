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
    int z;
    int handPos;
    int result;
    int testPassed = 0;
    int testFailed = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
            sea_hag, tribute, smithy};

    for (i = 0; i < 1000; i++)
    {
        numberPlayers = (rand() % 4) + 1;
        initializeGame(numberPlayers, k, RANDOM_SEED, &G);
        int randChoice1 = rand() % 2;
        int randChoice2 = rand() % 2;
        int currentPlayer = rand() % numberPlayers;
        z = 0;
        j = 0;
        handPos = rand() % 2;

        result =  minionFunc(randChoice1, randChoice2, z, j, &G, handPos, currentPlayer);

        if (result == -103)
        {
            testFailed++;
        }
        else if (result == -104)
        {
            testFailed++;
        }
        else
        {
            testPassed++;
        } 
    }
    printf("Minion Function\n"); 
    printf("# of Tests Passed: %d\n", testPassed); 
    printf("# of Tests Failed: %d\n", testFailed); 

    return 0;
    
}