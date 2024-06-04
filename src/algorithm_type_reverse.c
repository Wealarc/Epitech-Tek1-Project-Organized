/*
** EPITECH PROJECT, 2023
** algorithm type
** File description:
** algorithm type
*/

#include "../include/shell.h"

linked_list_t *sorting_function_type_rev(linked_list_t *first_node,
    linked_list_t *second_node)
{
    linked_list_t *final_list = NULL;

    if (first_node == NULL)
        return (second_node);
    if (second_node == NULL)
        return (first_node);
    if (my_strcmp(first_node->type, second_node->type) >= 0){
        final_list = first_node;
        final_list->next =
            sorting_function_type_rev(first_node->next, second_node);
    } else {
        final_list = second_node;
        final_list->next =
            sorting_function_type_rev(first_node, second_node->next);
    }
    return (final_list);
}

int algorithm_tri_type_rev(linked_list_t **tete)
{
    linked_list_t *begin = *tete;
    linked_list_t *left_node;
    linked_list_t *right_node;

    if (begin == NULL || begin->next == NULL){
        return (0);
    }
    preparing_two_nodes(begin, &left_node, &right_node);
    algorithm_tri_type_rev(&left_node);
    algorithm_tri_type_rev(&right_node);
    *tete = sorting_function_type_rev(left_node, right_node);
}
