/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "my.h"
#include <string.h>

int error_fd(const char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1) {
        return -1;
    }
    return fd;
}

int main(int ac, const char **av)
{
    char *buffer = NULL;
    char **buf = NULL;

    if (ac != 2)
        return 84;
    if(error_fd(av)== -1)
        return 84;
    buffer = open_file(av[1]);
    if (buffer == NULL || strlen(buffer) == 0)
        return 84;
    buf = pars_file(av);
    if (buf == NULL) {
        return 84;
    }
    if(check_word_letter(buffer, buf) == 84)
        return 84;
    free(buf);
    free(buffer);
    return 0;
}