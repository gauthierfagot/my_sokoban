/*
** EPITECH PROJECT, 2023
** create_array
** File description:
** create_array
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

static int count_lines(char *buffer)
{
    int i = 0;
    int nb_lines = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            nb_lines ++;
        i ++;
    }
    return nb_lines;
}

static int line_size(char *buffer, int *j)
{
    int i = 0;
    int x = *j;

    while (buffer[x] != '\n' && buffer[x] != '\0') {
        i ++;
        x ++;
    }
    return i;
}

static char *read_line(int *j, char *buffer)
{
    int l_size = line_size(buffer, j);
    char *str = malloc(sizeof(char) * (l_size + 1));
    int i = 0;

    while (buffer[*j] != '\n' && buffer[*j] != '\0') {
        str[i] = buffer[*j];
        i ++;
        *j = *j + 1;
    }
    str[i] = '\0';
    *j = *j + 1;
    return str;
}

static int add_line(char **res, int nb_lines, int *j, char *buffer)
{
    for (int i = 0; i < nb_lines; i ++) {
        res[i] = read_line(j, buffer);
    }
    res[nb_lines] = NULL;
    return 0;
}

char **create_map(char *buffer)
{
    int nb_lines = count_lines(buffer);
    char **res = malloc(sizeof(char *) * (nb_lines + 1));
    int count = 0;
    int *j = &count;

    add_line(res, nb_lines, j, buffer);
    return res;
}
