/*
** EPITECH PROJECT, 2023
** disp function
** File description:
** disp function
*/

#include "../include/shell.h"

static void show_list(linked_list_t *link)
{
    my_putstr(link->type);
    my_putstr(" n°");
    my_put_nbr(link->num);
    my_putstr(" - \"");
    my_putstr(link->name);
    my_putstr("\"\n");
}

int disp(void *data, char **args)
{
    linked_list_t **begin = (linked_list_t **)data;
    linked_list_t *link = *begin;

    if (args[0] != NULL)
        return (84);
    while (link != NULL){
        show_list(link);
        link = link->next;
    }
    return (0);
}
