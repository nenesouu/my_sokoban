/*
** EPITECH PROJECT, 2023
** check_all
** File description:
** errors
*/

#include "../include/sokoban.h"
#include "../include/struct.h"
#include "../include/proto.h"

void check_line(char *buff, int *cnt, int width, int *fail,
    int *player, int *i)
{
    if (buff[*i] == '\n' && *cnt == (width + 1))
        *cnt = 0;
    else if (buff[*i] == '\n' && *cnt != (width + 1))
        *fail = 1;
}

void check_p(char *buff, int *player, int *i)
{
    if (buff[*i] == 'P')
        *player = *player + 1;
}

int check_valid_map(char *buff, int width, int height)
{
    int fail = 0;
    int cnt = 0;
    int player = 0;
    int i = 0;

    while (buff[i] != '\0' && fail == 0) {
        cnt = cnt + 1;
        check_line(buff, &cnt, width, &fail, &player, &i);
        check_p(buff, &player, &i);
        i = i + 1;
    }
    if (player != 1)
        fail = 1;
    return fail;
}
