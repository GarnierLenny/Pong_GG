/*
** EPITECH PROJECT, 2020
** ncurses_test
** File description:
** test
*/

#include "my.h"

int main(int ac, char **av)
{
    game_t *g = malloc(sizeof(game_t));
    g->ball = NULL;
    g->p1 = NULL;
    g->p2 = NULL;

    if (usage(ac, av) == 1)
        return 0;
    init_ncurses();
    g = init_g(g);
    g = set_point_l(g);
    reset_ball(g);
    game_loop(g);
    endwin();
    return 0;
}