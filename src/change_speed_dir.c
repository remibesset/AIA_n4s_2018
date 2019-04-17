/*
** EPITECH PROJECT, 2019
** change speed direction
** File description:
** change spd dir
*/

#include "n4s.h"

int set_speed(float center_street)
{
    int	i;

    if (center_street >= 2000)
        i = execute_commande("car_forward:1.0\n");
    else if (center_street >= 1500)
        i = execute_commande("car_forward:0.8\n");
    else if (center_street >= 1000)
        i = execute_commande("car_forward:0.5\n");
    else if (center_street >= 600)
        i = execute_commande("car_forward:0.4\n");
    else if (center_street >= 400)
        i = execute_commande("car_forward:0.2\n");
    else
        i = execute_commande("car_forward:0.1\n");
    return (i);
}

int set_dir_left_right(float calcul, char* command)
{
    my_putstr("WHEELS_DIR:");
    if (calcul <= 0.0)
        my_putchar('-');
    my_putstr(command);
    return (execute_commande("\0"));
}

int set_dir(float center_street, char **tab)
{
    float left_dir = atof(tab[1]);
    float rigth_dir = atof(tab[31]);
    int i = 0;

    if (center_street >= 1500)
        i = set_dir_left_right(left_dir - rigth_dir, "0.005\n");
    else if (center_street >= 1000)
        i = set_dir_left_right(left_dir - rigth_dir, "0.O5\n");
    else if (center_street >= 600)
        i = set_dir_left_right(left_dir - rigth_dir, "0.1\n");
    else if (center_street >= 400)
        i = set_dir_left_right(left_dir - rigth_dir, "0.3\n");
    else if (center_street >= 200)
        i = set_dir_left_right(left_dir - rigth_dir, "0.5\n");
    else
        i = set_dir_left_right(left_dir - rigth_dir, "0.7\n");
    return (i);
}