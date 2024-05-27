/*
** EPITECH PROJECT, 2023
** check_stat_game
** File description:
** check_stat_game
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int compare_box_storage(game_t *game, int i, int j)
{
    if (game->boxes[i]->y == game->storages[j]->y &&
        game->boxes[i]->x == game->storages[j]->x)
        return 1;
    return 0;
}

int win_condition(game_t *game)
{
    int count = 0;

    for (int i = 0; i < game->nb_boxes; i ++) {
        for (int j = 0; j < game->nb_storages; j ++) {
            count += compare_box_storage(game, i, j);
        }
    }
    if (count == game->nb_storages)
        game->stat_game = 0;
    return count;
}

int movement_blocked(game_t *game, int i)
{
    int block = 0;

    if ((game->map[game->boxes[i]->y - 1][game->boxes[i]->x] == '#' ||
        game->map[game->boxes[i]->y - 1][game->boxes[i]->x] == 'X') ||
        (game->map[game->boxes[i]->y + 1][game->boxes[i]->x] == '#' ||
        game->map[game->boxes[i]->y + 1][game->boxes[i]->x] == 'X'))
        block++;
    if ((game->map[game->boxes[i]->y][game->boxes[i]->x + 1] == '#' ||
        game->map[game->boxes[i]->y][game->boxes[i]->x + 1] == 'X') ||
        (game->map[game->boxes[i]->y][game->boxes[i]->x - 1] == '#' ||
        game->map[game->boxes[i]->y][game->boxes[i]->x - 1] == 'X'))
        block++;
    if (block >= 2)
        return 1;
    return 0;
}

void loose_condition(game_t *game)
{
    int blocked_box = 0;

    for (int i = 0; i < game->nb_boxes; i ++) {
        blocked_box += movement_blocked(game, i);
    }
    if (blocked_box == game->nb_boxes)
        game->stat_game = 1;
}

void check_stat(game_t *game)
{
    win_condition(game);
    loose_condition(game);
}
