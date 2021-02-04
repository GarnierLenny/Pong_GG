/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** init_g
*/

#include "my.h"

game_t *init_g(game_t *g)
{
    g->ball = NULL;
    g->p1 = NULL;
    g->p2 = NULL;

    g->point_l = 2;
    g->delay = 80;
    g->ball = init_struct(g->ball);
    g->p1 = init_player(g->p1, 1);
    getmaxyx(stdscr, g->ball->ym, g->ball->xm);
    getmaxyx(stdscr, g->p1->ymax, g->ball->xm);
    g->p2 = init_player(g->p2, g->ball->xm - 3);
    getmaxyx(stdscr, g->p2->ymax, g->ball->xm);
    return g;
}