/*
** EPITECH PROJECT, 2023
** my_strisnum
** File description:
** string with full numbers
*/

#include "../include/shell.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++){
        if ((str[i] >= '0' && str[i] <= '9'))
            continue;
        return (0);
    }
    return (1);
}
