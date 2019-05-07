/*
** EPITECH PROJECT, 2019
** change speed direction
** File description:
** change spd dir
*/

#include "n4s.h"
#include <string.h>
#include <stdio.h>

void my_putstr_error(char *str)
{
    write(2, str, my_strlen(str));
}

char *my_strcat(char *src, char *dest)
{
    int size = my_strlen(dest) + my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * (size));
    int i = 0;
    int j = 0;

    for (int i = 0; i < size; result[i] = '\0', i++);
    while (src[i] != '\0') {
        result[i] = src[i];
        i++;
    }
    while (dest[j] != '\0')
        result[i++] = dest[j++];
    result[i] = '\0';
    return (result);
}

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

    // if (center_street >= 2000)
    //     i = execute_commande("car_forward:1.0\n");
    // else if (center_street >= 1500)
    //     i = execute_commande("car_forward:0.8\n");
    // else if (center_street >= 1000)
    //     i = execute_commande("car_forward:0.5\n");
    // else if (center_street >= 600)
    //     i = execute_commande("car_forward:0.4\n");
    // else if (center_street >= 400)
    //     i = execute_commande("car_forward:0.2\n");
    // else
    //     i = execute_commande("car_forward:0.1\n");
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

char *precision_commande(int center)
{
    float number = 0.0;
    char *result = malloc(sizeof(char) * 5);

    for (int i = 0; i < 5; result[i] = '\0', i++);
    //number = ((-0.00038) * center) + 0.576;
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


    // if (center_street >= 1500)
    //     i = set_dir_left_right(left_dir - rigth_dir, "0.005\n");
    // else if (center_street >= 1000)
    //     i = set_dir_left_right(left_dir - rigth_dir, "0.05\n");
    // else if (center_street >= 600)
    //     i = set_dir_left_right(left_dir - rigth_dir, "0.1\n");
    // else if (center_street >= 400)
    //     i = set_dir_left_right(left_dir - rigth_dir, "0.3\n");
    // else if (center_street >= 200)
    //     i = set_dir_left_right(left_dir - rigth_dir, "0.5\n");
    // else
    //     i = set_dir_left_right(left_dir - rigth_dir, "0.7\n");
    return (i);
}