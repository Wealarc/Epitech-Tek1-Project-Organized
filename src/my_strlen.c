/*
** EPITECH PROJECT, 2023
** strlen
** File description:
** size of a string
*/

#include "../include/shell.h"

int my_strlen(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++){
        size = size + 1;
    }
    return (size);
}
