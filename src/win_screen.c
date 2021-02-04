/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** win_screen
*/

#include "my.h"

game_t *win_screen(game_t *g)
{
    if (g->p1->points == g->point_l) {
        clear();
        mvprintw((g->ball->ym / 2) - 1,
                (g->ball->xm / 2) - 5, "PLAYER 1 WINS !");
        g = init_g(g);
        refresh();
        sleep(3);
        g = set_point_l(g);
    }
    if (g->p2->points == g->point_l) {
        clear();
        mvprintw((g->ball->ym / 2) - 1,
                (g->ball->xm / 2) - 5, "PLAYER 2 WINS !");
        g = init_g(g);
        refresh();
        sleep(3);
        g = set_point_l(g);
    }
    return g;
}