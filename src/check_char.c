/*
** EPITECH PROJECT, 2023
** chekc
** File description:
** duo05
*/

char check_char(char c)
{
    if (c >= 65 && c <= 90)
        return c + 32;
    else
        return c;
}
