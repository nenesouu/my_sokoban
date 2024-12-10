/*
** EPITECH PROJECT, 2023
** proto
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "struct.h"
    #include "../lib/mini_printf.h"
    #include "../lib/my.h"

void win_or_fail(int win);
void game_loop(sokoban_t *game);
char *open_file(const char *filepath);
int get_map_size(sokoban_t *game);
void allocate_array(sokoban_t *game);
void get_position(sokoban_t *game);
void manage_touch(sokoban_t *game);
void upp_key(sokoban_t *game);
void down_key(sokoban_t *game);
void right_key(sokoban_t *game);
void left_key(sokoban_t *game);
int check_all(int argc, char **argv, sokoban_t *game);
void help_usage(void);
int check_valid_map(char *buff, int width, int height);
void add_o(sokoban_t *game);
int check_any_o(sokoban_t *game, int x, int y, int *count);
void game_over(sokoban_t *game);
int is_blocked(sokoban_t *game, int x, int y, int *nb_x);
void free_everything(sokoban_t *game);
int mini_printf(const char *format, ...);
int my_strcmp(char const *s1, char const *s2);

#endif /* !PROTO_H_ */
