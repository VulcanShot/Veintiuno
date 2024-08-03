#include "veintiuno.h"
#include "statistics.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include <string.h>

#define TARGET_NUMBER 21
#define TRIAL_COUNT 9999

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    int player_count, user_index;
    int results[player_count];

    if (argc < 2)
    {
        help();
    }
    else if (strcmp(argv[1], "spec") == 0)
    {
        initial_prompt(&player_count);
        memset(results, 0, player_count * sizeof(int));
        
        for (size_t i = 0; i < TRIAL_COUNT; i++)
        {
            int loser = get_loser(player_count, 0, 0);
            results[loser]++;
        }

        printf("----------------------------------------------\n");
        for (size_t i = 0; i < player_count; i++)
        {
            float _rate = rate(results, player_count, i, TRIAL_COUNT);
            printf("    %d   |    %f    \n", (int) i + 1, _rate);
        }
        printf("----------------------------------------------\n\n");
    }
    else if (strcmp(argv[1], "play") == 0)
    {
        initial_prompt(&player_count);

        printf("Which is the position of the player? (1, 2, ...) ");
        scanf("%d", &user_index);
        user_index--; // Adjust to 0-index

        for (size_t choice = 0; choice < choice_count; choice++)
        {
            memset(results, 0, player_count * sizeof(int));

            printf("-------- Games where player played %d ---------\n", choices[choice]);

            for (size_t i = 0; i < TRIAL_COUNT; i++)
            {
                int loser = get_loser(player_count, choices[choice], user_index);
                results[loser]++;
            }

            for (size_t i = 0; i < player_count; i++)
            {
                float _rate = rate(results, player_count, i, TRIAL_COUNT);
                printf("    %d   |    %f    \n", (int) i + 1, _rate);
            }
        }
    }
    else
    {
        help();
    }

    return 0;
}

void help(void)
{
    printf("Veintiuno Simulator. The available commands are the following:\n");
    printf("\tspec : Simulate a game as an spectator\n");
    printf("\tplay : Simulate a game as a player\n");
    printf("\thelp : Display the help message\n");
    exit(1);
}

void initial_prompt(int *player_count_ptr)
{
    printf("Welcome to Veintiuno\n");
    printf("How many players shall participate in the game? ");
    scanf("%d", player_count_ptr);
}

int get_loser(const int player_count, const int user_choice, const int user_index)
{
    int count = TARGET_NUMBER;
    int players[player_count];

    for (size_t i = 0; i < player_count; i++)
    {
        players[i] = get_random_choice();
    }

    if (user_choice != 0)
    {
        players[user_index] = user_choice;
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
    return random_inclusive(choices[0], choices[choice_count]);
}