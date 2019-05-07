/*
** EPITECH PROJECT, 2019
** change direction
** File description:
** change dir
*/

#include "n4s.h"
#include <string.h>
#include <stdio.h>

int set_dir_left_right(float calcul, char* command)
{
    my_putstr("WHEELS_DIR:");
    if (calcul <= 0.0)
        my_putchar('-');
    my_putstr(command);
    return (execute_commande("\0"));
}

char *precision_commande(int center)
{
    float number = 0.0;
    char *result = malloc(sizeof(char) * 5);

    for (int i = 0; i < 5; result[i] = '\0', i++);
    number = (-0.00042) * center + 0.576;
    gcvt(number, 3, result);
    result[my_strlen(result)] = '\n';
    return (result);
}

int set_dir(float center_street, char **tab)
{
    float left_dir = atof(tab[1]);
    float rigth_dir = atof(tab[31]);
    char *pres_command;
    int i = 0;

    if (center_street >= 1500)
        i = set_dir_left_right(left_dir - rigth_dir, "0.005\n");
    else if (center_street < 200)
        i = set_dir_left_right(left_dir - rigth_dir, "0.7\n");
    else {
        pres_command = precision_commande(center_street);
        i = set_dir_left_right(left_dir - rigth_dir, pres_command);
    }
    return (i);
}