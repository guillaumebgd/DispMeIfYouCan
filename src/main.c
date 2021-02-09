/*
** EPITECH PROJECT, 2020
** StumperLike
** File description:
** main.c
*/

#include "dispme.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    return dispme(av[1]);
}
