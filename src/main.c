/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/struct.h"
#include "../include/proto.h"
#include "../include/sokoban.h"

void free_everything(sokoban_t *game)
{
    int i = 0;

    free(game->buff);
    while (i < game->height) {
        free(game->map[i]);
        i = i + 1;
    }
    free(game->map);
    i = 0;
    while (i < game->height) {
        free(game->save_map[i]);
        i = i + 1;
    }
    free(game->save_map);
}

int main(int argc, char **argv)
{
    sokoban_t game = { .c = ' ' };

    if (check_all(argc, argv, &game) == 84)
        return game.error;
    if (get_map_size(&game) == 84)
        return 84;
    while (game.c == ' ') {
        allocate_array(&game);
        get_position(&game);
        game_loop(&game);
    }
    free_everything(&game);
    win_or_fail(game.win);
    return game.win;
}
