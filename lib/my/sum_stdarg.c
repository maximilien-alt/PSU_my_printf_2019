/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** sum_stdarg.c
*/

#include <stdlib.h>
#include <stdarg.h>

int my_strlen(char const *str);

int sum_stdarg(int i, int nb, ...)
{
    int sum = 0;
    va_list ap;

    va_start(ap, nb);
    if (i == 0) {
        while (nb > 0) {
            sum += (int) va_arg(ap, int);
            nb += -1;
        }
    } else {
        while (nb > 0) {
            sum += my_strlen((char *) va_arg(ap, char *));
            nb += -1;
        }
    }
    va_end(ap);
    return (sum);
}
