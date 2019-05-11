/*
** EPITECH PROJECT, 2019
** Detect finish
** File description:
** detect the end of track
*/

#include "n4s.h"

int detect_finish(char *str)
{
    char *end_str = xmalloc(sizeof(char) * (my_strlen(str) / 2));
    int count2Point = 0;
    int i = my_strlen(str);

    for (int j = 0; j < my_strlen(str) / 2; end_str[j] = '\0', j++);
    for (i; count2Point != 2 && i > 0; i--)
        if (str[i] == ':')
            count2Point++;
    i += 2;
    for (int j = 0; count2Point == 2 && str[i] != ':' && str[i] != '\0'; i++,
        j++)
        end_str[j] = str[i];
    if (my_strcmp(end_str, "Track Cleared") == 1) {
        execute_commande("stop_simulation\n");
        free(end_str);
        return (1);
    }
    free(end_str);
    return (0);
}