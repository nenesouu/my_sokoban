/*
** EPITECH PROJECT, 2023
** error handling
** File description:
** errors_handlings
*/

#include "../include/proto.h"
#include "../include/sokoban.h"
#include "../include/struct.h"

int handle_invalid_argument(sokoban_t *game)
{
    write(2, "not enough arguments, retry with -h!\n", 38);
    game->error = 84;
    return 84;
}

int handle_help_argument(sokoban_t *game)
{
    help_usage();
    game->error = 0;
    return 84;
}

int handle_invalid_map(sokoban_t *game)
{
    write(2, "Invalid map\n", 12);
    game->error = 84;
    return 84;
}

int check_all(int argc, char **argv, sokoban_t *game)
{
    if (argc != 2) {
        return handle_invalid_argument(game);
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        return handle_help_argument(game);
    }
    game->buff = open_file(argv[1]);
    if (game->buff == 0) {
        return handle_invalid_map(game);
    }
    return 0;
}

void help_usage(void)
{
    write(1, "USAGE\n", 7);
    write(1, "     ./my_sokoban map\n", 23);
    write(1, "DESCRIPTION\n", 13);
    write(1, "     map file representing the warehouse map,", 46);
    write(1, " containing ‘#’ for walls.\n", 32);
    write(1, "    ‘P’ for the player, ‘X’ for boxes and ‘O’", 58);
    write(1, "for storage locations.\n", 24);
}
