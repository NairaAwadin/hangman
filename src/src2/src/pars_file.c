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
    int size = 0;
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || stat(filepath, &buf) == -1)
        return NULL;
    //stat(filepath, &buf);
    //if (stat(filepath, &buf) == -1)
      //  return NULL;
    size = buf.st_size;
    if (size == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return NULL;
    //read(fd, buffer, size);
    if (read(fd, buffer, size) == -1)
        return NULL;
    close(fd);
    buffer[size] = '\0';
    return buffer;
}

void get_lines_file(char **buf, FILE *stream, int i, int line)
{
    size_t len = 0;

    while ((getline(&buf[i], &len, stream)) != -1 && i < line) {
        i += 1;
        if (i >= line) {
            break;
        }
    }
}

char **pars_file(const char **av)
{
    char *buffer = open_file(av[1]);
    //size_t len = 0;
    int i = 0;
    int line = get_stline(buffer);
    if (line == 0)
        return NULL;
    FILE *stream = fopen(av[1], "r");
    char **buf = malloc(sizeof(char*) * (line + 1));

    if (stream == NULL ||  buf == NULL) {
        return NULL;
    }
    for (int i = 0; i <= line; i++) {
        buf[i] = NULL;
    }
    /*while ((getline(&buf[i], &len, stream)) != -1 && i < line) {
        i += 1;
        if (i >= line) {
            break;
        }
    }*/
    get_lines_file(buf, stream, i, line);
    fclose(stream);
    free (buffer);
    return buf;
}
