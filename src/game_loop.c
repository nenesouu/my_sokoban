/*
** EPITECH PROJECT, 2023
** game loop
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"
#include "../include/proto.h"
#include "../include/struct.h"

void win_or_fail(int win)
{
    if (win == 0)
        printf("\n congrats bro, you win!!! / wanna restart ? y/n \n\n");
    else
        printf("\n sorry bro...you failed:( / wanna restart ? y/n \n\n");
}

void initialize_game_window(sokoban_t *game)
{
    int i = 0;

    initscr();
    curs_set(0);
    game->c = 'w';
    game->win = 1;
    while (i < game->height) {
        clear();
        mvprintw(i, 0, game->map[i]);
        i = i + 1;
    }
}

void run_game_loop(sokoban_t *game)
{
    int i = 0;

    while (game->c != 'q' && game->c != ' ' && game->win == 1) {
        clear();
        i = 0;
        while (i < game->height) {
            mvprintw(i, 0, game->map[i]);
            i = i + 1;
        }
        mvprintw(game->player_y, game->player_x, "P");
        refresh();
        manage_touch(game);
    }
    endwin();
}

void game_loop(sokoban_t *game)
{
    initialize_game_window(game);
    run_game_loop(game);
}
