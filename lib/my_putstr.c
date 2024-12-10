/*
** EPITECH PROJECT, 2023
** day4
** File description:
** my_putstr
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
