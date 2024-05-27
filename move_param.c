/*
** EPITECH PROJECT, 2023
** move_param
** File description:
** move_param
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int box_index(game_t *game, int x, int y)
{
    for (int i = 0; i < game->nb_boxes; i ++) {
        if (game->boxes[i]->x == x && game->boxes[i]->y == y)
            return i;
    }
}

int move_box(game_t *game, int x, int y, int index)
{
    if (game->map[y][x] == ' ' || game->map[y][x] == 'O') {
        game->map[y][x] = 'X';
        game->boxes[index]->y = y;
        game->boxes[index]->x = x;
        return 0;
    }
    return 1;
}

void move_player(game_t *game, int x, int y)
{
    game->map[y][x] = 'P';
    game->map[game->player->y][game->player->x] = ' ';
    game->player->y = y;
    game->player->x = x;
}

static void move_up(game_t *game, int x, int y)
{
    if (game->map[y][x] == ' ') {
        move_player(game, x, y);
    }
    if (game->map[y][x] == 'X') {
        if (move_box(game, x, y - 1, box_index(game, x, y)) == 1)
            return;
        game->map[y][x] = ' ';
        move_up(game, x, y);
    }
    if (game->map[y][x] == 'O') {
        move_player(game, x, y);
    }
}

static void move_down(game_t *game, int x, int y)
{
    if (game->map[y][x] == ' ') {
        move_player(game, x, y);
    }
    if (game->map[y][x] == 'X') {
        if (move_box(game, x, y + 1, box_index(game, x, y)) == 1)
            return;
        game->map[y][x] = ' ';
        move_down(game, x, y);
    }
    if (game->map[y][x] == 'O') {
        move_player(game, x, y);
    }
}

static void move_right(game_t *game, int x, int y)
{
    if (game->map[y][x] == ' ') {
        move_player(game, x, y);
    }
    if (game->map[y][x] == 'X') {
        if (move_box(game, x + 1, y, box_index(game, x, y)) == 1)
            return;
        game->map[y][x] = ' ';
        move_right(game, x, y);
    }
    if (game->map[y][x] == 'O') {
        move_player(game, x, y);
    }
}

static void move_left(game_t *game, int x, int y)
{
    if (game->map[y][x] == ' ') {
        move_player(game, x, y);
    }
    if (game->map[y][x] == 'X') {
        if (move_box(game, x - 1, y, box_index(game, x, y)) == 1)
            return;
        game->map[y][x] = ' ';
        move_left(game, x, y);
    }
    if (game->map[y][x] == 'O') {
        move_player(game, x, y);
    }
}

void replace_storage(game_t *game)
{
    for (int i = 0; i < game->nb_storages; i ++) {
        if (game->map[game->storages[i]->y][game->storages[i]->x] == ' ')
            game->map[game->storages[i]->y][game->storages[i]->x] = 'O';
    }
}

int search_key(int key, game_t *game)
{
    switch (key) {
    case 27:
        return 1;
    case ' ':
        return 2;
    case KEY_UP:
        move_up(game, game->player->x, game->player->y - 1);
        break;
    case KEY_DOWN:
        move_down(game, game->player->x, game->player->y + 1);
        break;
    case KEY_RIGHT:
        move_right(game, game->player->x + 1, game->player->y);
        break;
    case KEY_LEFT:
        move_left(game, game->player->x - 1, game->player->y);
        break;
    }
    replace_storage(game);
    return game->stat_game;
}
