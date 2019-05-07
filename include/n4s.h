/*
** EPITECH PROJECT, 2019
** makefile
** File description:
** makefile
*/

#ifndef N4S_H
#define N4S_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>
#include "get_next_line.h"

//get_next_line.c
char *get_next_line(int fd);
char *my_realloc(char *src);

//my_lib.c
void my_putstr(char *str);
void my_putchar(char);
int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);

//utils.c
char **my_str_to_word_tab(char *str, char separator, int *nb_argument);
char **my_realloc_charchar(char **list, int k, char *name);
char *take_new_str_for_tab(char *str);
char *my_strcat(char *src, char *dest);

//verif_malloc.c
void *xmalloc(int size);

//change_speed.c
int set_speed(float mid);

//change_dir.c
int set_dir(float mid, char **tab);
int set_dir_left_right(float calcul, char* command);

//main.c
int detect_finish(char *str);
int execute_commande(char *str);

//free.c
void free_function(char **tab, char *str);

#endif