#include "veintiuno.h"
#include "statistics.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#define TARGET_NUMBER 21
#define TRIAL_COUNT 9999

int main()
{
    srand(time(NULL));
    
    const int choices[] = { 1, 2 };
    size_t choice_count = sizeof(choices) / sizeof(choices[0]);
    int player_count;

    printf("How many players shall participate in the game? ");
    scanf("%d", &player_count);

    int results[TRIAL_COUNT];
    
    printf("---- After %d games, the results show: \n", TRIAL_COUNT);
    for (size_t choice = 0; choice < choice_count; choice++)
    {
        printf("-------- Games where player played %d ---------\n", choices[choice]);

        for (size_t i = 0; i < TRIAL_COUNT; i++)
        {
            int loser = get_loser(choices[choice], player_count);
            results[i] = loser + 1; // Correct the 0-based index
        }

        printf("----------------------------------------------\n");
        printf("        Mean    |   Mode    |   LooseRate    \n");
        printf("        %.2f    |   %.2f    |   %.2f      \n", mean(results, TRIAL_COUNT),
                                                               mode(results, TRIAL_COUNT),
                                                               rate(results, TRIAL_COUNT, 1));
        printf("----------------------------------------------\n\n");
    }

    return 0;
}

int get_loser(int user_choice, int player_count)
{
    int count = TARGET_NUMBER;
    int players[player_count];
    players[0] = user_choice;

    for (size_t i = 1; i < player_count; i++)
    {
        players[i] = get_random_choice();
    }

    for (;;)
    {
        for (size_t i = 0; i < player_count; i++)
        {
            count -= players[i];
            if (count <= 0)
                return i;
        }
    }
}

int get_random_choice()
{
    return (rand() % 2) + 1;
}