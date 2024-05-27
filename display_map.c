/*
** EPITECH PROJECT, 2023
** display_map
** File description:
** display_map
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int flag_h(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     ");
    my_putstr("map file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n");
    my_putstr("         'P' for the player, 'X' for boxes and ");
    my_putstr("'O' for storage locations.\n");
    return 0;
}

void **dump_array(char *const *map)
{
    for (int i = 0; map[i] != NULL; i ++) {
        printw(map[i]);
        printw("\n");
    }
}

int search_x_max(game_t *game)
{
    int tmp = 0;
    int x_max = 0;

    for (int i = 0; game->map[i] != NULL; i ++) {
        tmp = x_max;
        x_max = my_strlen(game->map[i]);
        if (x_max < tmp)
            x_max = tmp;
    }
    return x_max + 1;
}

int search_y_max(game_t *game)
{
    int i = 0;

    while (game->map[i] != NULL) {
        i ++;
    }
    return i;
}

void display_game(WINDOW *screen, game_t *game)
{
    int x = 0;
    int y = 0;
    int x_max = search_x_max(game);
    int y_max = search_y_max(game);
    char *mess = "Please, Enlarge the terminal";

    getmaxyx(screen, y, x);
    if (x < x_max || y < y_max)
        mvprintw(LINES / 2, (COLS / 2) - (my_strlen(mess) / 2), mess);
    else
        dump_array(game->map);
}
