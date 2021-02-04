/*
** EPITECH PROJECT, 2020
** ncurses_test
** File description:
** player
*/

#include "my.h"

game_t *reset_player_pos(game_t *g)
{
    g->p1->pos_y = (g->ball->ym / 2) - 1;
    g->p2->pos_y = (g->ball->ym / 2) - 1;
    return g;
}

player_t *init_player(player_t *p, int pos_x)
{
    p = malloc(sizeof(player_t));

    p->pos_x = pos_x;
    p->pos_y = 1;
    p->ymin = 1;
    p->vel = 1;
    p->points = 0;
    return p;
}

void disp_players_points(game_t *g)
{
    int mid = (g->ball->xm) / 2;
    int yp = 2;

    mvprintw(yp, mid - 10, "%d", g->p1->points);
    mvprintw(yp, mid + 10, "%d", g->p2->points);
    refresh();
}

void disp_player(player_t *p)
{
    mvprintw(p->pos_y, p->pos_x, "||");
    mvprintw(p->pos_y + 1, p->pos_x, "||");
    mvprintw(p->pos_y + 2, p->pos_x, "||");
    refresh();
}

player_t *move_player(player_t *p, char *keys, char c)
{
    disp_player(p);
    if (c != keys[0] && c != keys[1])
        return p;
    if (c == keys[0] && p->pos_y >= p->ymin)
        p->pos_y -= 1;
    if (c == keys[1] && p->pos_y < (p->ymax - 3))
        p->pos_y += 1;
    return p;
}