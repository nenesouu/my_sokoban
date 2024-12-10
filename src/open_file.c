/*
** EPITECH PROJECT, 2023
** open file
** File description:
** open_file
*/

#include "../include/sokoban.h"
#include "../include/proto.h"

int get_file_size(const char *filepath)
{
    struct stat buff;

    if (stat(filepath, &buff) == -1) {
        return -1;
    }
    if (S_ISDIR(buff.st_mode)) {
        return -1;
    }
    return buff.st_size;
}

char *read_file_contents(int file_des, int size)
{
    int b_read;
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (buffer == NULL) {
        close(file_des);
        return NULL;
    }
    b_read = read(file_des, buffer, size);
    if (b_read < 0) {
        close(file_des);
        free(buffer);
        return NULL;
    }
    buffer[size] = '\0';
    close(file_des);
    return buffer;
}

char *open_file(const char *filepath)
{
    int size;
    int file_des = open(filepath, O_RDONLY);

    if (file_des == -1) {
        return NULL;
    }
    size = get_file_size(filepath);
    if (size == -1 || size == 0) {
        close(file_des);
        return NULL;
    }
    return read_file_contents(file_des, size);
}
