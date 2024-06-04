/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#ifndef SHELL_H
    #define SHELL_H

typedef struct linked_list_s {
    int num;
    char *type;
    char *name;
    struct linked_list_s *next;
} linked_list_t;

// To be implemented
void preparing_two_nodes(linked_list_t *link, linked_list_t **left_node,
    linked_list_t **right_node);
int algorithm_tri_type_rev(linked_list_t **tete);
int algorithm_tri_name_rev(linked_list_t **tete);
int algorithm_tri_id_rev(linked_list_t **tete);
int my_strcmp(char const *s1, char const *s2);
int algorithm_tri_type(linked_list_t **tete);
int algorithm_tri_name(linked_list_t **tete);
int algorithm_tri_id(linked_list_t **tete);
int my_str_isnum(char const *str);
int sort(void *data, char **args);
int disp(void *data, char **args);
int add(void *data, char **args);
int del(void *data, char **args);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
