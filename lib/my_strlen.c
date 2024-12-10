/*
** EPITECH PROJECT, 2023
** day4
** File description:
** my_strlen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
