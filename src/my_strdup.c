/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-leo.roos
** File description:
** my_strdup
*/

#include "../include/shell.h"

char *my_strdup(char *str)
{
    int i = 0;
    int size = my_strlen(str) + 1;
    char *rv = malloc(sizeof(char) * size);

    for (; str[i] != '\0'; i++){
        rv[i] = str[i];
    }
    rv[i] = '\0';
    return (rv);
}
