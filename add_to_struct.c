/*
** EPITECH PROJECT, 2023
** add_to_struct
** File description:
** add_to_struct
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

box_t *create_box(int i, int j)
{
    box_t *box = malloc(sizeof(box_t));

    box->x_start = j;
    box->y_start = i;
    box->x = j;
    box->y = i;
    return box;
}

storage_t *create_storage(int i, int j)
{
    storage_t *storage = malloc(sizeof(storage_t));

    storage->x = j;
    storage->y = i;
    return storage;
}

int add_box(game_t *game, int i, int j, int boxes_i)
{
    if (game->map[i][j] == 'X') {
        game->boxes[boxes_i] = create_box(i, j);
        boxes_i++;
    }
    return boxes_i;
}

int add_storage(game_t *game, int i, int j, int storages_i)
{
    if (game->map[i][j] == 'O') {
        game->storages[storages_i] = create_storage(i, j);
        storages_i++;
    }
    return storages_i;
}

void add_box_and_storage(char **map, game_t *game, box_t **boxes,
    storage_t **storages)
{
    int boxes_i = 0;
    int storages_i = 0;

    game->boxes = boxes;
    game->storages = storages;
    for (int i = 0; map[i] != NULL; i ++) {
        for (int j = 0; map[i][j] != '\0'; j ++) {
            boxes_i = add_box(game, i, j, boxes_i);
            storages_i = add_storage(game, i, j, storages_i);
        }
    }
    game->boxes[boxes_i] = NULL;
    game->storages[storages_i] = NULL;
}
