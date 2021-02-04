/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** print_misc
*/

#include "my.h"

void disp_point_lim(game_t *g)
{
    mvprintw(1, (g->ball->xm) / 2, "%d", g->point_l);
}

void disp_mid_line(game_t *g)
{
    int x = (g->ball->xm) / 2;
    int y = 2;

    mvprintw(y - 2, x, "%c", '|');
    for (; y < g->ball->ym; y++)
        mvprintw(y, x, "%c", '|');
    refresh();
}