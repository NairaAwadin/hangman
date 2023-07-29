/*
** EPITECH PROJECT, 2023
** 3
** File description:
** check_win_lose
*/

#include "my.h"
#include <stdio.h>
#include <string.h>

int check_win_lose_round(size_t round, char *word, char *cp_input, char *star)
{
    int i = 0;

    if (strcmp(cp_input, word) == 0) {
        printf("\nYou won!\n");
        i = 1;
        return i;
    }
    if (round == strlen(word)) {
        printf("\nYou lost!\n");
        i = 1;
        return i;
    }
    if (strlen(cp_input) == strlen(word)
        && strcmp(cp_input, word) != 0) {
        printf("%s\n", star);
        //round++;
        printf("Round %ld\n", round); //pk size_t
    }
    return i;
}
