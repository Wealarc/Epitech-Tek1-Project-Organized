/*
** EPITECH PROJECT, 2023
** commands principales
** File description:
** commands principales
*/

#include "../include/shell.h"

static void function_printing_add(linked_list_t *link)
{
    my_putstr(link->type);
    my_putstr(" n°");
    my_put_nbr(link->num);
    my_putstr(" - \"");
    my_putstr(link->name);
    my_putstr("\" added.\n");
}

static int verif_add(char **args)
{
    if (args[0] == NULL){
        return (84);
    }
    for (int i = 0; args[i] != NULL; i++){
        if (my_strcmp(args[i], "DEVICE") != 0 &&
            my_strcmp(args[i], "ACTUATOR") != 0 &&
            my_strcmp(args[i], "SENSOR") != 0 &&
            my_strcmp(args[i], "PROCESSOR") != 0 &&
            my_strcmp(args[i], "WIRE") != 0)
            return (84);
        i++;
        if (args[i] == NULL){
            return (84);
        }
    }
    return (0);
}

int add(void *data, char **args)
{
    static int idx = 0;
    linked_list_t **begin = (linked_list_t **)data;
    linked_list_t *link = *begin;

    if (verif_add(args) == 84)
        return (84);
    for (int i = 0; args[i] != NULL; i++){
        link = malloc(sizeof(linked_list_t));
        link->type = my_strdup(args[i]);
        link->name = my_strdup(args[i + 1]);
        link->num = idx;
        function_printing_add(link);
        link->next = *begin;
        *begin = link;
        i++;
        idx++;
    }
    return (0);
}

int my_strcmp_node(int vl, char *ref)
{
    int v2 = my_getnbr(ref);

    if (vl == v2){
        return (1);
    }
    return (0);
}

static void function_printing_del(linked_list_t *link)
{
    my_putstr(link->type);
    my_putstr(" n°");
    my_put_nbr(link->num);
    my_putstr(" - \"");
    my_putstr(link->name);
    my_putstr("\" deleted.\n");
}

int del_extension(linked_list_t **begin, linked_list_t *link,
    linked_list_t *prev)
{
    linked_list_t *to_free;

    to_free = link;
    if (prev == NULL){
        *begin = link->next;
        link = link->next;
    } else {
        prev->next = link->next;
        link = link->next;
    }
    free(to_free);
    return (0);
}

void del_function_supp(linked_list_t *link,
    linked_list_t **begin, linked_list_t *prev)
{
    function_printing_del(link);
    del_extension(begin, link, prev);
}

static int verif_del(char **args)
{
    for (int i = 0; args[i] != NULL; i++){
        if (my_str_isnum(args[i]) == 0)
            return (84);
    }
    return (0);
}

int del(void *data, char **args)
{
    linked_list_t **begin = (linked_list_t **)data;
    linked_list_t *link = NULL;
    linked_list_t *prev = NULL;

    if (verif_del(args) == 84)
        return (84);
    if (!args || !args[0])
        return (84);
    link = (*begin);
    while (link != NULL){
        if (my_strcmp_node(link->num, args[0]) != 0){
            del_function_supp(link, begin, prev);
    } else {
        prev = link;
        link = link->next;
    }
    }
    if (args[1] != NULL)
        return del(data, &args[1]);
}
