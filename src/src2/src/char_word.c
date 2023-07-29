/*
** EPITECH PROJECT, 2023
** lolo
** File description:
** char_word
*/

#include "my.h"
#include <string.h>
#include <stdio.h>

char *replace_char_in_word(char *input, char *word, int count, char *star)
{
    if (strlen(input) != strlen(word)) {
        return NULL;
    }
    for (size_t a = 0; word[a] != '\n'; a++) {
        for (int j = 0; input[j] != '\n'; j++) {
            star[j] = (word[a] == input[j] && count > 0
            && input[a] != word[a]) ? '?' : star[j];
            copy_if_char(input, word, star, a);
            star[0] = word[0];
        }
    }
    return star;
}

int check_if_char_in_word(char *copy_input, char *word, int i, int tmp)
{
    for (int j = 0; copy_input[j] != '\n'; j++) {
        if (copy_input[j] == word[i])
            tmp++;
    }
    return tmp;
}

void print_len_word(char *copy_input, char *word)
{
    if (strlen(copy_input) < strlen(word)) {
        printf("Word too short. Retry.\n");
    }
    if (strlen(copy_input) > strlen(word)) {
        printf("Word too long. Retry.\n");
    }
}

void complete_word(char *word, char *cp_input, char *copy, char *star_word)
{
    int tmp = 0;

    print_len_word(cp_input, word);
    for (int i = 0; word[i] != '\n'; i++) {
        int count = check_if_char_in_word(cp_input, word, i, tmp);
        replace_char_in_word(cp_input, copy, count, star_word);
    }
}

int print_word(char *copy_word, char *copy, char *word, char *star_word)
{
    char *input = NULL;
    //int tmp = 0;
    size_t size = 100;
    size_t round = 1;

    printf(">");
    while (getline(&input, &size, stdin) != -1) {
        star_word = convert_word(copy_word);
        //print_len_word(cp_input, word);
        complete_word(word, input, copy, star_word);
        /*for (int i = 0; word[i] != '\n'; i++) {
          int count = check_if_char_in_word(cp_input, word, i, tmp);
          replace_char_in_word(cp_input, copy, count, star_word);
          }*/

        if (strlen(input) == strlen(word) && strcmp(input, word) != 0)
            round++;
        int w_l = check_win_lose_round(round, word, input, star_word);
        if (w_l == 1)
            break;
        printf(">");
    }
    free(input);
    return 0;
}

void print_debut(char *star_word, char *copy)
{
    printf("*: invalind letter\n");
    printf("?: incorectly placed letter\n");
    printf("Will you find the secret word?\n");
    star_word[0] = copy[0];
    printf("%s\n", star_word);
    printf("Round 1\n");
}

int check_word_letter(char *buffer, char **buf)
{
    int line = get_stline(buffer);
    char *word = aleat_word(buf, line);
    char *copy = strdup(word);
    char *copy_word = strdup(word);
    char *star_word = convert_word(copy_word);

    if (copy == NULL)
        return 84;
    if (copy_word == NULL)
        return 84;
    print_debut(star_word, copy);
    /*printf("*: invalind letter\n");
    printf("?: incorectly placed letter\n");
    printf("Will you find the secret word?\n");
    star_word[0] = copy[0];
    printf("%s\n", star_word);
    printf("Round 1\n");*/
    if(print_word(copy_word, copy, word, star_word) == 84)
        return 84;
    for (int i = 0; buf[i] != NULL; i++) {
        free(buf[i]);
    }
    free(copy);
    free(copy_word);
    return 0;
}

