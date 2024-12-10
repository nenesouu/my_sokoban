/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-iness.el-atouani
** File description:
** check_box
*/

#include "../include/proto.h"
#include "../include/sokoban.h"
#include "../include/struct.h"

int is_blocked_hor(sokoban_t *game, int x, int y)
{
    int i = -1;

    while (i < 3) {
        if (game->map[y][x] == 'X' && game->map[y][x + i] == '#' &&
            game->map[y + 1][x] == '#') {
            return 1;
        }
        i = i + 2;
    }
    return 0;
}

int is_blocked_ver(sokoban_t *game, int x, int y)
{
    int i = -1;

    while (i < 3) {
        if (game->map[y][x] == 'X' && game->map[y][x + i] == '#' &&
            game->map[y - 1][x] == '#') {
            return 1;
        }
        i = i + 2;
    }
    return 0;
}

int is_blocked(sokoban_t *game, int x, int y, int *nb_x)
{
    int i = 0;

    if (is_blocked_hor(game, x, y)) {
        i++;
    }
    if (is_blocked_ver(game, x, y)) {
        i++;
    }
    if (game->map[y][x] == 'X') {
        *nb_x = *nb_x + 1;
    }
    return i;
}
