/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_2_my_printf.c
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>

int my_printf(char *format, ...);

Test(my_printf, should_print_C_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%X", 12);
    cr_assert_stdout_eq_str("C");
}

Test(my_printf, should_print_34_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%o", 28);
    cr_assert_stdout_eq_str("34");
}

Test(my_printf, should_print_101111_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%b", 47);
    cr_assert_stdout_eq_str("101111");
}

Test(my_printf, should_print_23_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%u", 23);
    cr_assert_stdout_eq_str("23");
}

Test(my_printf, should_print_hello_worrld_into_stdout)
{
    cr_redirect_stdout();
    my_printf("hel%s", "lo_world");
    cr_assert_stdout_eq_str("hello_world");
}