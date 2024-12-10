/*
** EPITECH PROJECT, 2023
** game over
** File description:
** end
*/

#include "../include/sokoban.h"
#include "../include/proto.h"
#include "../include/struct.h"

void add_o(sokoban_t *game)
{
    int count = 0;
    int o = 0;
    int y = 0;
    int x;

    while (y < game->height) {
        x = 0;
        while (x < game->width) {
            o = o + check_any_o(game, x, y, &count);
            x = x + 1;
        }
        y = y + 1;
    }
    if (count == o && o > 0)
        game->win = 0;
}

int check_any_o(sokoban_t *game, int x, int y, int *count)
{
    int o = 0;

    if (game->save_map[y][x] == 'O') {
        *count = *count + 1;
        if (game->map[y][x] != 'X')
            game->map[y][x] = 'O';
        else
            o = o + 1;
    }
    return (o);
}

void game_over(sokoban_t *game)
{
    int nb_x = 0;
    int b = 0;
    int x;
    int y = 0;

    while (y < game->height) {
        x = 0;
        while (x < game->width) {
            b = b + is_blocked(game, x, y, &nb_x);
            x = x + 1;
        }
        y = y + 1;
    }
    if (nb_x == b && b != 0)
        game->c = 'q';
}
