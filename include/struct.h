/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct sokoban_s{
    char *buff;
    int error;
    int width;
    int height;
    char **map;
    char **save_map;
    int player_x;
    int player_y;
    char c;
    int win;
} sokoban_t;

#endif /* !STRUCT_H_ */
