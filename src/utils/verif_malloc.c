/*
** EPITECH PROJECT, 2019
** verfi malloc
** File description:
** verif
*/

#include "n4s.h"

void *xmalloc(int size)
{
    void *ptr = malloc(size);
    char err_msg[] = "Malloc failed !\n";

    if (ptr == NULL) {
        write(2, err_msg, my_strlen(err_msg));
        exit(84);
    }
    return (ptr);
}