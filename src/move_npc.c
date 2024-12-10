/*
** EPITECH PROJECT, 2023
** manage touch
** File description:
** moves
*/

#include "../include/sokoban.h"
#include "../include/struct.h"
#include "../include/proto.h"

void manage_touch(sokoban_t *game)
{
    game->c = getch();
    switch (game->c) {
        case 'A':
            upp_key(game);
            break;
        case 'B':
            down_key(game);
            break;
        case 'C':
            right_key(game);
            break;
        case 'D':
            left_key(game);
            break;
        default:
            break;
    }
}

void upp_key(sokoban_t *game)
{
    if (game->map[game->player_y - 1][game->player_x] != '#' &&
    game->map[game->player_y - 1][game->player_x] != 'X')
        game->player_y = game->player_y - 1;
    else if (game->map[game->player_y - 1][game->player_x] == 'X' &&
    game->map[game->player_y - 2][game->player_x] != 'X' &&
    game->map[game->player_y - 2][game->player_x] != '#') {
        game->player_y = game->player_y - 1;
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y - 1][game->player_x] = 'X';
    }
    add_o(game);
    game_over(game);
}

void down_key(sokoban_t *game)
{
    if (game->map[game->player_y + 1][game->player_x] != '#' &&
    game->map[game->player_y + 1][game->player_x] != 'X')
        game->player_y = game->player_y + 1;
    else if (game->map[game->player_y + 1][game->player_x] == 'X' &&
    game->map[game->player_y + 2][game->player_x] != 'X' &&
    game->map[game->player_y + 2][game->player_x] != '#') {
        game->player_y = game->player_y + 1;
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y + 1][game->player_x] = 'X';
    }
    add_o(game);
    game_over(game);
}

void right_key(sokoban_t *game)
{
    if (game->map[game->player_y][game->player_x + 1] != '#' &&
    game->map[game->player_y][game->player_x + 1] != 'X')
        game->player_x = game->player_x + 1;
    else if (game->map[game->player_y][game->player_x + 1] == 'X' &&
    game->map[game->player_y][game->player_x + 2] != 'X' &&
    game->map[game->player_y][game->player_x + 2] != '#') {
        game->player_x = game->player_x + 1;
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y][game->player_x + 1] = 'X';
    }
    add_o(game);
    game_over(game);
}

void left_key(sokoban_t *game)
{
    if (game->map[game->player_y][game->player_x - 1] != '#' &&
    game->map[game->player_y][game->player_x - 1] != 'X')
        game->player_x = game->player_x - 1;
    else if (game->map[game->player_y][game->player_x - 1] == 'X' &&
    game->map[game->player_y][game->player_x - 2] != 'X' &&
    game->map[game->player_y][game->player_x - 2] != '#') {
        game->player_x = game->player_x - 1;
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y][game->player_x - 1] = 'X';
    }
    add_o(game);
    game_over(game);
}
