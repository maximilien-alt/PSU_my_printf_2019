/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_file_size.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_file_size(char *filepath)
{
    struct stat file_t;
    int result = stat(filepath, &file_t);

    if (result != 0)
        return (-1);
    return (file_t.st_size);
}