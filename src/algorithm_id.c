/*
** EPITECH PROJECT, 2023
** algorithm id
** File description:
** algorithm id
*/

#include "../include/shell.h"

linked_list_t *sorting_function_id(linked_list_t *first_node,
    linked_list_t *second_node)
{
    linked_list_t *final_list = NULL;

    if (first_node == NULL)
        return (second_node);
    if (second_node == NULL)
        return (first_node);
    if (first_node->num <= second_node->num){
        final_list = first_node;
        final_list->next = sorting_function_id(first_node->next, second_node);
    } else {
        final_list = second_node;
        final_list->next = sorting_function_id(first_node, second_node->next);
    }
    return (final_list);
}

void preparing_two_nodes(linked_list_t *link, linked_list_t **left_node,
    linked_list_t **right_node)
{
    linked_list_t *first_node;
    linked_list_t *second_node;

    second_node = link;
    first_node = link->next;
    while (first_node != NULL){
        first_node = first_node->next;
        if (first_node != NULL){
            first_node = first_node->next;
            second_node = second_node->next;
        }
    }
    *left_node = link;
    *right_node = second_node->next;
    second_node->next = NULL;
}

int algorithm_tri_id(linked_list_t **tete)
{
    linked_list_t *begin = *tete;
    linked_list_t *left_node;
    linked_list_t *right_node;

    if (begin == NULL || begin->next == NULL){
        return (0);
    }
    preparing_two_nodes(begin, &left_node, &right_node);
    algorithm_tri_id(&left_node);
    algorithm_tri_id(&right_node);
    *tete = sorting_function_id(left_node, right_node);
}
