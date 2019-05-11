/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "n4s.h"

int execute_commande(char *str)
{
    char *new_line;

    my_putstr(str);
    new_line = get_next_line(0);
    if (detect_finish(new_line) == 1)
        return (1);
    free(new_line);
    return (0);
}

int change_speed_dir(char *str, char **tab, int dir, int speed)
{
    float center_street = atof(tab[15]);

    if (speed == 1) {
        if (set_speed(center_street) == 1)
            return (1);
    }
    if (dir == 1)
        if (set_dir(center_street, tab) == 1)
            return (1);
    free_function(tab, str);
}

int parse_commande(int dir, int speed)
{
    char *str;
    char **tab = NULL;
    float center_street = 0;
    int nb_arg = 0;

    my_putstr("get_info_lidar\n");
    str = get_next_line(0);
    if (str != NULL) {
        if (detect_finish(str) == 1)
            return (1);
        str = take_new_str_for_tab(str);
        tab = my_str_to_word_tab(str, ':', &nb_arg);
    }
    if (tab == NULL || my_strlen_tab(tab) < 30)
        parse_commande(dir, speed);
    else
        change_speed_dir(str, tab, dir, speed);
    return (0);
}

void do_ia(void)
{
    while (1) {
        if (parse_commande(0, 1) == 1)
            break;
        if (parse_commande(1, 0) == 1)
            break;
    }
}

int main(void)
{
    execute_commande("START_SIMULATION\n");
    do_ia();
    return (0);
}