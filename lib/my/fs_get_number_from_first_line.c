/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
** fs_get_number_from_first_line.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int is_number(char c)
{
    return (c >= '0' && c <= '9');
}

int my_get_number_line(char *buffer)
{
    int res = 0;
    int cursor = 0;

    while (buffer[cursor] != '\n' && is_number(buffer[cursor])) {
        res = res * 10;
        res = res + buffer[cursor] - '0';
        if (res < 0)
            return (-1);
        cursor += 1;
    }
    free (buffer);
    return (res);
}

int fs_get_number_from_first_line(char const *filepath)
{
    char *buffer;
    int fd = open(filepath, O_RDONLY);

    if (fd <= 0)
        return (-1);
    buffer = malloc(sizeof(char) * 32000);
    read(fd, buffer, 32000);
    close (fd);
    return (my_get_number_line(buffer));
}

/*int main(int ac, char *av[])
{
    int result = fs_get_number_from_first_line(av[1]);
    my_put_nbr(result);
    return (0);
}*/
