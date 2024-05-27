/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** error_handling
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

static int array_len(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        i ++;
    }
    return i;
}

static void array_cpy(char **array, char **dest, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
        dest[i] = my_strcpy(dest[i], array[i]);
        i ++;
    }
    dest[i] = NULL;
}

void add_game_map(char **map, game_t *game)
{
    int n = array_len(map);
    char **dest = malloc(sizeof(char *) * (n + 1));

    array_cpy(map, dest, n);
    game->map = dest;
}

int count_object(char **map, game_t *game, int i, int j)
{
    if (map[i][j] == 'P') {
        game->nb_player += 1;
        game->player->x = j;
        game->player->y = i;
    }
    if (map[i][j] == 'X')
        game->nb_boxes += 1;
    if (map[i][j] == 'O')
        game->nb_storages += 1;
    if (map[i][j] != 'X' && map[i][j] != 'O' && map[i][j] != ' '
        && map[i][j] != '\n' && map[i][j] != '#' && map[i][j] != 'P')
            return 84;
    return 0;
}

int search_object(char **map, game_t *game, box_t **boxes,
    storage_t **storages)
{
    int error = 0;

    game->nb_boxes = 0;
    game->nb_storages = 0;
    game->nb_player = 0;
    game->stat_game = 3;
    for (int i = 0; map[i] != NULL; i ++) {
        for (int j = 0; map[i][j] != '\0'; j ++) {
            error += count_object(map, game, i, j);
        }
    }
    if (game->nb_boxes < game->nb_storages || game->nb_player != 1 ||
        error != 0 || game->nb_boxes == 0 || game->nb_storages == 0)
        return 84;
    return 0;
}

int check_valid_map(char **map, game_t *game, box_t **boxes,
    storage_t **storages)
{
    if (search_object(map, game, boxes, storages) == 84)
        return 84;
    add_game_map(map, game);
}
