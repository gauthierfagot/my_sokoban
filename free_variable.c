/*
** EPITECH PROJECT, 2023
** free_variable
** File description:
** free_variable
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i ++) {
        free(array[i]);
    }
}

void free_boxes(box_t **boxes)
{
    for (int i = 0; boxes[i] != NULL; i ++) {
        free(boxes[i]);
    }
}

void free_storages(storage_t **storages)
{
    for (int i = 0; storages[i] != NULL; i ++) {
        free(storages[i]);
    }
}

void leave_game(char **map, game_t *game)
{
    endwin();
    free_array(map);
    free(map);
    free_array(game->map);
    free(game->map);
    free_boxes(game->boxes);
    free_storages(game->storages);
    free(game->boxes);
    free(game->storages);
}
