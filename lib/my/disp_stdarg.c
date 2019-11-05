/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** disp_stdarg.c
*/

#include <stdlib.h>
#include <stdarg.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int disp_stdarg(char *s, ...)
{
    int cursor = 0;
    va_list ap;

    va_start(ap, s);
    while (s[cursor]) {
        if (s[cursor] == 's') {
            my_putstr((char *) va_arg(ap, char *));
        }
        if (s[cursor] == 'c') {
            my_putchar(va_arg(ap, int));
        }
        if (s[cursor] == 'i') {
            my_put_nbr((int) va_arg(ap, int));
        }
        my_putchar('\n');
        cursor += 1;
    }
    va_end(ap);
    return (0);
}
