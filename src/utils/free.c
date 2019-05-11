/*
** EPITECH PROJECT, 2019
** free
** File description:
** free
*/

#include "n4s.h"

void free_function(char **tab, char *str)
{
    for (int i = 0; tab[i] == NULL; i++)
        free(tab[i]);
    free(tab);
    free(str);
}