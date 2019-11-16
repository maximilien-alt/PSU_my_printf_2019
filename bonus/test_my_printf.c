/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_my_printf.c
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>

int my_printf(char *format, ...);

Test(my_printf, should_print_hello_into_stdout)
{
    cr_redirect_stdout();
    my_printf("hello");
    cr_assert_stdout_eq_str("hello");
}


Test(my_printf, should_print_o_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%c", 'o');
    cr_assert_stdout_eq_str("o");
}

Test(my_printf, should_print_12_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%d", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, should_print_ABC_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%s", "ABC");
    cr_assert_stdout_eq_str("ABC");
}

Test(my_printf, should_print_c_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%x", 12);
    cr_assert_stdout_eq_str("c");
}