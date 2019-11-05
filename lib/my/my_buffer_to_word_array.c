/*
** EPITECH PROJECT, 2019
** CPool_2019
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>

int is_bsq(char c)
{
    return (c == 'o' || c == '.');
}

int my_nb_word1(char const *str)
{
    int number = 0;

    for (int letter = 0; str[letter]; letter += 1) {
        if (letter == 0 && is_bsq(str[letter]))
            number += 1;
        else if ((is_bsq(str[letter])) && !(is_bsq(str[letter - 1]))){
            number += 1;
        }
    }
    return (number);
}

char **my_word_in_tab1(char const *str, char **tab)
{
    int letter = 0;
    int cursor = 0;
    int num = 0;

    while ((!(is_bsq(str[letter]))) && str[letter])
    letter += 1;
    while (str[letter]) {
        num = 0;
        while (is_bsq(str[letter]) && str[letter]) {
            tab[cursor][num] = str[letter];
            letter += 1;
            num += 1;
        }
        tab[cursor][num] = '\0';
        cursor += 1;
        while ((!(is_bsq(str[letter]))) && str[letter])
            letter += 1;
    }
    return (tab);
}

char **my_get_word1(char const *str, char **tab)
{
    int letter = 0;
    int cursor = 0;
    int num = 0;

    while ((!(is_bsq(str[letter]))) && str[letter])
    letter += 1;
    while (str[letter]) {
        num = 0;
        while (is_bsq(str[letter]) && str[letter]) {
            letter += 1;
            num += 1;
        }
        tab[cursor] = malloc(sizeof(char) * (num + 1));
        cursor += 1;
        while ((!(is_bsq(str[letter]))) && str[letter])
            letter += 1;
    }
    return (my_word_in_tab1(str, tab));
}

char **my_buffer_to_word_array(char const *str)
{
    char **tab;
    int a = my_nb_word1(str);

    tab = malloc(sizeof(char *) * (a + 1));
    tab[a] = NULL;
    my_get_word1(str, tab);
    return (tab);
}