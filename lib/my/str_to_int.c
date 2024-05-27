/*
** EPITECH PROJECT, 2023
** str_to_int
** File description:
** str_to_int
*/
#include "lib.h"

int str_to_int(char *str)
{
    int nb = 0;
    int n = my_strlen(str) - 1;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i ++) {
        if (str[i] == '-') {
            i ++;
            n --;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb + (str[i] - 48) * my_compute_power_rec(10, n);
            n --;
        } else {
            return 84;
        }
    }
    if (str[0] == '-') {
        nb = nb * -1;
    }
    return nb;
}
