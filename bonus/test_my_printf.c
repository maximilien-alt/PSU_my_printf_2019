/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_my_printf.c
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>

int my_printf(char *format, ...);

Test(my_printf, should_print_o_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%c", 'o');
    cr_assert_stdout_eq_str("o");
}