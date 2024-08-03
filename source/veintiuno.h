#ifndef VEINTIUNO_H
#define VEINTIUNO_H

#include <stdlib.h>

const static int choices[] = { 1, 2 };
const static size_t choice_count = sizeof(choices) / sizeof(choices[0]);

void help(void);
void initial_prompt(int *player_count_ptr);
int get_loser(const int user_choice, const int user_index, const int player_count);
int get_random_choice(void);

#endif // !VEINTIUNO_H