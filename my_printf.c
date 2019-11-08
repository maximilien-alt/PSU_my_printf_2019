/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);

void my_print_s(va_list ap);

void my_print_c(va_list ap);

void my_print_d(va_list ap);

void my_print_p(va_list ap);

void my_print_x(va_list ap);

void my_print_X(va_list ap);

void my_print_o(va_list ap);

void my_print_b(va_list ap);

void my_print_S(va_list ap);

typedef struct format_t
{
    char c;
    void (*ptr)(va_list);
} format_t;

static format_t tab[10] =
{
    {'s', my_print_s},
    {'c', my_print_c},
    {'d', my_print_d},
    {'i', my_print_d},
    {'p', my_print_p},
    {'x', my_print_x},
    {'X', my_print_X},
    {'o', my_print_o},
    {'b', my_print_b},
    {'S', my_print_S}
};

void my_print(char *str, va_list ap, ...)
{
    for (int i = 0; i <= 10; i += 1) {
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