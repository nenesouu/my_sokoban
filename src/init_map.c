/*
** EPITECH PROJECT, 2023
** init map
** File description:
** set_map
*/

#include "../include/sokoban.h"
#include "../include/struct.h"
#include "../include/proto.h"

int get_map_size(sokoban_t *game)
{
    int j;
    int i = 0;

    game->height = 1;
    game->width = 0;
    while (game->buff[i] != '\0') {
        if (game->buff[i] == '\n')
            game->height = game->height + 1;
        i = i + 1;
    }
    j = 0;
    while (game->buff[j] != '\n') {
        game->width = game->width + 1;
        j = j + 1;
    }
    if (game->width < 4 || game->height < 3 ||
        check_valid_map(game->buff, game->width, game->height) == 1)
        return (84);
    else
        return (0);
}

void find_player_position(sokoban_t *game, int *player_x, int *player_y)
{
    int index = 0;
    int x;
    int y;

    while (index < game->width * game->height) {
        x = index % game->width;
        y = index / game->width;
        if (game->map[y][x] == 'P') {
            *player_x = x;
            *player_y = y;
            return;
        }
        index++;
    }
}

void get_position(sokoban_t *game)
{
    int player_x = 0;
    int player_y = 0;

    find_player_position(game, &player_x, &player_y);
    game->player_x = player_x;
    game->player_y = player_y;
    game->map[player_y][player_x] = ' ';
}
