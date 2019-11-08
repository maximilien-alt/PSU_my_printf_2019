/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnbr_base.c
*/

void my_putchar(char c);

int my_strlen(char *str);

void my_putnbr_base(long long nbr, char *base)
{
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_base(nbr / len, base);
    }
    nbr = nbr % len;
    my_putchar(base[nbr]);
}