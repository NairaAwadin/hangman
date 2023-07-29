/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** game.c
*/

#include "my.h"
#include <string.h>

int check_found(char *s_word, char letter, char *copy)
{
    int found = 0;

    for (int l = 0; s_word[l] != '\n'; l++) {
        if (copy[l] == check_char(letter)) {
            found = 1;
        }
    }
    return found;
}

int loop(char *s_word, char letter, char *copy)
{
    int found = 0;

    for (int l = 0; s_word[l] != '\n'; l++) {
        if (copy[l] == check_char(letter)) {
            s_word[l] = check_char(letter);
            found = 1;
        }
    }
    if (check_found(s_word, letter, copy) == 0) {
        printf("%c: is not in this word\n", letter);
    }
    return 0;
}

void printf_letter(char *s_word, char letter, char *copy, int tries)
{
    char *input = NULL;
    size_t size = 100;

    while (getline(&input, &size, stdin) != -1) {
        if (!check_found(s_word, letter, copy))
            tries--;
    loop(s_word, letter, copy);
        printf("%sTries: %d\n\n", s_word, tries);
        if (tries == 0) {
            printf("You lost!\n");
            break;
        }
        if (strcmp(s_word, copy) == 0) {
            printf("Congratulations!\n");
            break;
    }
        printf("Your letter: ");
        scanf(" %c", &letter);
    }
}

void check_input_letter(char *s_word, char *copy, int tries)
{
    char letter;

    printf("Tries: %d\n\nYour letter: ", tries);
    scanf(" %c", &letter);
    printf_letter(s_word, letter, copy, tries);
}

int check_word_letter(char *buffer, char **buf, int tries)
{
    int line = get_stline(buffer);
    char *word = aleat_word(buf, line);
    char *copy_word = strdup(word);
    char *star_word = convert_word(word);

    check_input_letter(star_word, copy_word, tries);
    for (int i = 0; buf[i] != NULL; i++) {
        free(buf[i]);
    }
    return 0;
}
