/*
** EPITECH PROJECT, 2020
** StumperLike
** File description:
** dispme.c
*/

#include <unistd.h>
#include <stdio.h>

int write_substring(char *str, int index, int times)
{
    int count = 0;
    int substring_length = 0;
    int substring_start = index;

    if (!str)
        return 84;
    while (str[index] != (times + '0')) {
        index += 1;
        substring_length += 1;
    }
    if (str[substring_start] == ' ')
        write(1, "\n", 1);
    while (times != 0) {
        if (str[substring_start] == ' ') {
            count = write(1, "\n", 1);
        } else {
            count = write(1, &str[substring_start], substring_length);
            write(1, "\n", 1);
        }
        if ((count == -1) || (count != substring_length))
            return 84;
        times -= 1;
    }
    return 0;
}

int dispme(char *str)
{
    int substring_index = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            write_substring(str, substring_index, str[i] - '0');
            substring_index = i + 1;
        } else if (str[i] == ' ') {
            write_substring(str, substring_index, 0);
            substring_index = i + 1;
        }
        i += 1;
    }
    return 0;
}
