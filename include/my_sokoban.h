/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban
*/
#include <ncurses.h>

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

typedef struct box {
    int x_start;
    int y_start;
    int x;
    int y;
} box_t;

typedef struct storage {
    int x;
    int y;
} storage_t;

typedef struct player {
    int x;
    int y;
} player_t;

typedef struct game {
    char **map;
    box_t **boxes;
    storage_t **storages;
    player_t *player;
    int nb_boxes;
    int nb_storages;
    int nb_player;
    int stat_game;
} game_t;

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);

int flag_h(void);
void display_game(WINDOW *screen, game_t *game);

char *read_buffer(char *filepath);
char **create_map(char *buffer);

int check_valid_map(char **map, game_t *game, box_t **boxes,
    storage_t **storages);

void add_box_and_storage(char **map, game_t *game, box_t **boxes,
    storage_t **storages);

void free_array(char **array);
void free_boxes(box_t **boxes);
void free_storages(storage_t **storages);
void leave_game(char **map, game_t *game);

void add_game_map(char **map, game_t *game);
int search_key(int key, game_t *game);

void check_stat(game_t *game);

#endif /* !MY_SOKOBAN_ */
