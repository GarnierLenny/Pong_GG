/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** game_loop
*/

#include "my.h"

void game_loop(game_t *g)
{
    int c = 0;

    while (1) {
        move_player(g->p1, "zs", c);
        move_player(g->p2, "pm", c);
        disp_players_points(g);
        disp_mid_line(g);
        move_ball(g);
        disp_point_lim(g);
        timeout(g->delay);
        c = getch();
        refresh();
        clear();
    }
}