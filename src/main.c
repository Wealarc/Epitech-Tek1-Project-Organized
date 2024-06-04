/*
** EPITECH PROJECT, 2023
** organised
** File description:
** organised
*/

#include "../include/shell.h"

static int checking_air_type(char *arg, void *data)
{
    if (arg != NULL && my_strcmp(arg, "-r") == 0){
        algorithm_tri_type_rev((linked_list_t **)data);
        return (1);
    }
    algorithm_tri_type((linked_list_t **)data);
    return (0);
}

static int checking_air_id(char *arg, void *data)
{
    if (arg != NULL && my_strcmp(arg, "-r") == 0){
        algorithm_tri_id_rev((linked_list_t **)data);
        return (1);
    }
    algorithm_tri_id((linked_list_t **)data);
    return (0);
}

static int checking_air_name(char *arg, void *data)
{
    if (arg != NULL && my_strcmp(arg, "-r") == 0){
        algorithm_tri_name_rev((linked_list_t **)data);
        return (1);
    }
    algorithm_tri_name((linked_list_t **)data);
    return (0);
}

static int sort_extension_deux(char **args, int i, void *data)
{
    if (my_strcmp(args[i], "ID") == 0){
        i = i + checking_air_id(args[i + 1], data);
        } else if (my_strcmp(args[i], "-r") == 0){
            return (0);
            } else {
                return (84);
                }
}

static int sort_extension(char **args, int i, void *data)
{
    if (my_strcmp(args[i], "TYPE") == 0){
        i = i + checking_air_type(args[i + 1], data);
    } else if (my_strcmp(args[i], "NAME") == 0){
        i = i + checking_air_name(args[i + 1], data);
    } else {
        return (sort_extension_deux(args, i, data));
    }
}

int sort(void *data, char **args)
{
    if (args[0] == NULL)
        return (84);
    for (int i = 0; args[i] != NULL; i++){
        if (sort_extension(args, i, data) == 84){
            return (84);
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    linked_list_t *list = NULL;

    if (argc != 1){
        return (84);
    }
    return (workshop_shell(&list));
}
