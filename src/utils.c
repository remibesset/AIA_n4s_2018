/*
** EPITECH PROJECT, 2019
** utils 1
** File description:
** utils function
*/

#include "n4s.h"

char **my_realloc_charchar(char **list, int k, char *name)
{
    char **new = xmalloc(sizeof(char *) * (k + 2));
    int i = 0;
    int j = 0;

    for (i; i < k; i++) {
        new[j] = list[i];
        j++;
    }
    new[j] = name;
    new[j + 1] = NULL;
    return (new);
}

char *take_str(int begin, int i, char *str)
{
    char *str_table = xmalloc(sizeof(char) * (i - begin + 3));
    int j = 0;

    for (int k = 0; k < (i - begin + 3); str_table[k] = '\0', k++);
    for (begin; begin < i; begin++) {
        str_table[j] = str[begin];
        j++;
    }
    return (str_table);
}

char **my_str_to_word_tab(char *str, char separator, int *nb_argument)
{
    char **table_str = xmalloc(sizeof(char *) * 1);
    int i = 0;
    int begin = 0;
    int sep_actif = 0;

    for (i; str[i] != '\0'; i++) {
        if (str[i] == separator && sep_actif == 0 || str[i + 1] == '\0') {
            sep_actif = 1;
            begin = (begin == 0) ? begin: begin + 1;
            table_str = (str[i + 1] != '\0') ? my_realloc_charchar(table_str, \
        (*nb_argument), take_str(begin, i, str)) : table_str;
            table_str = (str[i + 1] == '\0') ? my_realloc_charchar(table_str, \
        (*nb_argument), take_str(begin, i + 1, str)) : table_str;
            (*nb_argument)++;
            begin = i;
        } else if (str[i] == separator && sep_actif == 1)
            begin++;
        else
            sep_actif = 0;
    }
    return (table_str);
}

char *take_new_str_for_tab(char *str)
{
    char *new_str = xmalloc(sizeof(char) * (my_strlen(str) + 1));
    int count3Point = 0;
    int i = 0;
    int j = 0;

    for (int j = 0; j < my_strlen(str); new_str[j] = '\0', j++);
    for (i; count3Point != 3 && str[i] != '\0'; i++)
        if (str[i] == ':')
            count3Point++;
    for (i; str[i] != '\0'; i++)
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ':')
            new_str[j++] = str[i];
    return (new_str);
}