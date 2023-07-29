/*
** EPITECH PROJECT, 2023
** my random word
** File description:
** random word
*/

#include "my.h"
#include <time.h>
#include <string.h>

char *aleat_word(char **buf, int line)
{
    int i = 0;
    char *rand_word = NULL;

    srand(time(NULL));
    i = rand() % line;
    rand_word = buf[i];
    return rand_word;
}

char *convert_word(char *rand_word)
{
    int j = 0;
    char *s_word = rand_word;

    for (int i = 0; s_word[i] != '\n'; i++) {
        s_word[j] = '*';
        j++;
    }
    printf("%s", s_word);
    return s_word;
}
