/*
** EPITECH PROJECT, 2023
** parsing_the_file
** File description:
** duo05
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_stline(char *buffer)
{
    int n = 0;
    int count = 0;
    while (buffer[n] != '\0') {
        if (buffer[n] == '\n')
            count++;
        n++;
    }
    return (count);
}

char *open_file(const char *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    int fd = open(filepath, O_RDONLY);

    if (buffer == NULL)
        return NULL;
    read(fd, buffer, size);

    buffer[size] = '\0';
    close(fd);
    return buffer;
}

char **pars_file(char **av)
{
    char *buffer = open_file(av[1]);
    size_t len = 0;
    int i = 0;
    int line = get_stline(buffer);
    FILE *stream = fopen(av[1], "r");
    char **buf = malloc(sizeof(char*) * (line + 1));

    if (buf == NULL)
        return NULL;
    for (int i = 0; i <= line; i++) {
        buf[i] = NULL;
    }
    while ((getline(&buf[i], &len, stream)) != -1 && i < line) {
        i += 1;
        if (i >= line) {
            break;
        }
    }
    fclose(stream);
    return buf;
}
