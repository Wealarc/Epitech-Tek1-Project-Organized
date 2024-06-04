/*
** EPITECH PROJECT, 2023
** strmcp
** File description:
** compare two strings
*/

#include "../include/shell.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0'; i++){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
