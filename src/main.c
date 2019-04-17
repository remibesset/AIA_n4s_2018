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

int change_speed_dir(int dir, int speed)
{
    char *str;
    char **tab;
    float center_street;
    int nb_arg = 0;

    my_putstr("get_info_lidar\n");
    str = get_next_line(0);
    if (detect_finish(str) == 1)
        return (1);
    str = take_new_str_for_tab(str);
    tab = my_str_to_word_tab(str, ':', &nb_arg);
    center_street = atof(tab[15]);
    if (speed == 1)
        if (set_speed(center_street) == 1)
            return (1);
    if (dir == 1)
        if (set_dir(center_street, tab) == 1)
            return (1);
    free_function(tab, str);
    return (0);
}

void do_ia(void)
{
    while (1) {
        if (change_speed_dir(0, 1) == 1)
            break;
        if (change_speed_dir(1, 0) == 1)
            break;
    }
}

int main(void)
{
    execute_commande("START_SIMULATION\n");
    do_ia();
    return (0);
}