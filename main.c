/*
** EPITECH PROJECT, 2023
** my_sokkoban
** File description:
** my_sokoban
*/
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"

void reset(game_t *game, char **map)
{
    free_array(game->map);
    free(game->map);
    check_valid_map(map, game, game->boxes, game->storages);
    for (int i = 0; i < game->nb_boxes; i ++) {
        game->boxes[i]->y = game->boxes[i]->y_start;
        game->boxes[i]->x = game->boxes[i]->x_start;
    }
}

void check_all(char **map, WINDOW *screen, game_t *game)
{
    check_stat(game);
    if (game->stat_game == 0) {
        leave_game(map, game);
    }
    if (game->stat_game == 1) {
        leave_game(map, game);
    }
    if (game->stat_game == 2)
        reset(game, map);
}

int central_loop(char **map, game_t *game)
{
    WINDOW *screen;
    int key = 0;

    screen = initscr();
    keypad(screen, TRUE);
    curs_set(0);
    while (1) {
        clear();
        display_game(screen, game);
        refresh();
        check_all(map, screen, game);
        if (game->stat_game == 0 || game->stat_game == 1)
            return game->stat_game;
        key = getch();
        game->stat_game = search_key(key, game);
    }
}

int init_variable(char **map)
{
    WINDOW *screen = NULL;
    game_t game = {0};
    box_t **boxes = NULL;
    storage_t **storages = NULL;
    player_t player = {0, 0};

    game.player = &player;
    if (check_valid_map(map, &game, boxes, storages) == 84)
        return 84;
    boxes = malloc(sizeof(box_t *) * (game.nb_boxes + 1));
    storages = malloc(sizeof(storage_t *) * (game.nb_storages + 1));
    add_box_and_storage(map, &game, boxes, storages);
    return central_loop(map, &game);
}

int main(int argc, char **argv)
{
    char *buffer = NULL;
    char **map = NULL;
    int nb = 0;

    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return flag_h();
    buffer = read_buffer(argv[1]);
    if (buffer == NULL)
        return 84;
    map = create_map(buffer);
    nb = init_variable(map);
    free(buffer);
    return nb;
}
