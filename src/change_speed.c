/*
** EPITECH PROJECT, 2019
** change speed direction
** File description:
** change spd dir
*/

#include "n4s.h"
#include <string.h>
#include <stdio.h>

char *change_string(int center_street)
{
    float number = 0.0;
    char *result = malloc(sizeof(char) * 4);

    for (int i = 0; i < 4; result[i] = '\0', i++);
    number = 0.00044 * center_street + 0.107;
    gcvt(number, 2, result);
    return (result);
}

int set_speed(float center_street)
{
    int	i;
    char *str_take;
    char *concat_str;
    char forward_str[] = "CAR_FORWARD:\0";
    int j = 0;

    if (center_street > 2000)
        i = execute_commande("CAR_FORWARD:1.0\n");
    else if (center_street < 400)
        i = execute_commande("CAR_FORWARD:0.1\n");
    else {
        str_take = change_string(center_street);
        concat_str = my_strcat(forward_str, str_take);
        concat_str[my_strlen(concat_str)] = '\n';
        i = execute_commande(concat_str);
        free(concat_str);
    }
    return (i);
}