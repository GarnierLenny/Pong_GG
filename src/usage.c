/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** usage
*/

#include "my.h"

int str_comp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

int usage(int ac, char **av)
{
    if (ac == 2 && str_comp(av[1], "-h") == 1) {
        my_putstr("USAGE\n");
        my_putstr("    ./pong x\n");
        my_putstr("     x point limit (def=5)\n\n");
        my_putstr("POINT SET SCREEN\n");
        my_putstr("    You may set the point limit in the first screen\n");
        my_putstr("         'z': increase point limit by 1 (max:20)\n");
        my_putstr("         's': decrease point limit by 1 (min:1)\n");
        my_putstr("         'Enter': set point limit and lauch game\n");
        my_putstr("         'esc': exit game\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("    Play 1972 ATARI's Pong® replica with a friend !\n\n");
        my_putstr("    Player 1:\n");
        my_putstr("         'z': move left paddle up\n");
        my_putstr("         's': move left paddle down\n");
        my_putstr("    Player 2:\n");
        my_putstr("         'p': move right paddle up\n");
        my_putstr("         'm': move right paddle down\n\n");
        my_putstr("Enjoy !\n");
        return 1;
    }
    return 0;
}