/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** test_3_my_printf.c
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>

int my_printf(char *format, ...);

Test(my_printf, should_print_0xc_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%p", 12);
    cr_assert_stdout_eq_str("Oxc");
}


Test(my_printf, should_print_4294967295_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%u", -1);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, should_print_non_printable_into_stdout)
{
    char str[4] = "toto";

    str[2] = 6;
    cr_redirect_stdout();
    my_printf("%S", str);
    cr_assert_stdout_eq_str("to\006o");
}

Test(my_printf, should_print_purcent_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, should_print_K_into_stdout)
{
    cr_redirect_stdout();
    my_printf("%K");
    cr_assert_stdout_eq_str("K");
}