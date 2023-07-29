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
void print_len_word(char *copy_input, char *word);
char *open_file(const char *filepath);
char **pars_file(const char **av);
char *aleat_word(char **buf, int line);
char *convert_word(char *rand_word);
int check_word_letter(char *buffer, char **buf);
void copy_if_char(char *copy_input, char *copy_word, char *star_word, size_t a);
int check_win_lose_round(size_t round, char *word, char *cp_input, char *star);
#endif
