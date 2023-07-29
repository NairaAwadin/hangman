/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer = open_file(av[1]);
    char **buf = pars_file(av);

    if (ac != 2 && ac != 3)
        return 84;
    if (fd == -1)
        return 84;
    if (my_strlen(buffer) == 0)
        return 84;

    if (buf == NULL) {
        free(buffer);
        return 84;
    }
    tries_func(ac, av, buffer, buf);
    free(buf);
    free(buffer);
    return 0;
}
