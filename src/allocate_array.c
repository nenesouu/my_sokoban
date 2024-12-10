/*
** EPITECH PROJECT, 2023
** allocate array
** File description:
** allocate_array
*/

#include "../include/proto.h"
#include "../include/struct.h"
#include "../include/sokoban.h"

char **allocate_2d_array(int rows, int cols)
{
    char **array = malloc(sizeof(char *) * rows);
    int i = 0;

    while (i < rows) {
        array[i] = malloc(sizeof(char) * (cols + 2));
        i++;
    }
    return array;
}

void copy_string(char *dest, const char *src, int size)
{
    int i = 0;

    while (i < size) {
        dest[i] = src[i];
        i++;
    }
}

void initialize_sokoban(sokoban_t *game)
{
    game->map = allocate_2d_array(game->height, game->width);
    game->save_map = allocate_2d_array(game->height, game->width);
    game->player_x = 0;
    game->player_y = 0;
    game->c = ' ';
    game->win = 0;
    game->error = 0;
}

void allocate_array(sokoban_t *game)
{
    int array = 0;
    int i = 0;

    initialize_sokoban(game);
    while (i < game->height) {
        copy_string(game->map[i], game->buff + array, game->width + 1);
        game->map[i][game->width + 1] = '\0';
        copy_string(game->save_map[i], game->map[i], game->width + 1);
        array += game->width + 1;
        i++;
    }
}
