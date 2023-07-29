/*
** EPITECH PROJECT, 2023
** my_h
** File description:
** duo04
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>

char check_char(char c);
int my_strlen(char const *str);
int get_stline(char *buffer);
char *open_file(const char *filepath);
char **pars_file(char **av);
char *aleat_word(char **buf, int line);
char *convert_word(char *rand_word);
int check_word_letter(char *buffer, char **buf, int tries);
int tries_func(int ac, char **av, char *buffer, char **buf);
#endif
