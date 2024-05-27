/*
** EPITECH PROJECT, 2023
** create_buffer
** File description:
** create_buffer
*/
#include "my_sokoban.h"
#include <ncurses.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int buffer_size(char const *filepath)
{
    int size;
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        return 84;
    size = sb.st_size;
    return size;
}

char *read_buffer(char *filepath)
{
    int stream = open(filepath, O_RDONLY);
    int buf_size = buffer_size(filepath);
    char *buffer = malloc(sizeof(char) * (buf_size + 1));

    if (stream == -1 || buf_size == 84)
        return NULL;
    read(stream, buffer, buf_size);
    buffer[buf_size] = '\0';
    close(stream);
    return buffer;
}
