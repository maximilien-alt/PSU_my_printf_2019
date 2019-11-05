/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>

void my_putchar(char c);

void my_print_s(va_list ap);

void my_print_c(va_list ap);

void my_print_d(va_list ap);

typedef struct format_t
{
    char c;
    void (*ptr)(va_list);
} format_t;

static format_t tab[3] =
{
    {'s', my_print_s},
    {'c', my_print_c},
    {'d', my_print_d}
};

void my_print(char *str, va_list ap, ...)
{
    for (int i = 0; i <= 3; i += 1) {
        if (str[1] == tab[i].c) {
            tab[i].ptr(ap);
        }
    }
    return;
}

int my_printf(char *format, ...)
{
    int cursor = 0;
    va_list ap;

    va_start(ap, format);
    while (format[cursor]) {
        if (format[cursor] == '%') {
            my_print(&format[cursor], ap);
            cursor += 2;
        } else {
            my_putchar(format[cursor]);
            cursor += 1;
        }
    }
    va_end(ap);
    return (0);
}