/*
** EPITECH PROJECT, 2023
** chekc
** File description:
** duo05
*/

#include "my.h"
#include <string.h>

void copy_if_char(char *copy_input, char *copy_word, char *star_word, size_t a)
{
    if (strlen(copy_input) != strlen(copy_word))
        return;
    if (copy_input[a] == copy_word[a])
        star_word[a] = copy_word[a];
}

char check_char(char c)
{
    if (c >= 65 && c <= 90)
        return c + 32;
    else
        return c;
}
