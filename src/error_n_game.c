/*
** EPITECH PROJECT, 2023
** merge
** File description:
** func
*/

#include "my.h"

int tries_func(int ac, char **av, char *buffer, char **buf)
{
    int tries = 10;

    if (ac > 2) {
        tries = atoi(av[2]);
    }
    check_word_letter(buffer, buf, tries);
    return 0;
}
