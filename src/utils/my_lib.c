/*
** EPITECH PROJECT, 2018
** lib infinadd
** File description:
** lib for the infinadd
*/

#include "n4s.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strlen_tab(char **tab)
{
    int i = 0;

    for (i; tab[i] != 0; i++);
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strcmp(char *str1, char *str2)
{
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}