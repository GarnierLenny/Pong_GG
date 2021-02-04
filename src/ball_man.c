/*
** EPITECH PROJECT, 2020
** ncurses_test
** File description:
** ball_man
*/

#include "my.h"

ball_t *init_struct(ball_t *ball)
{
    time_t t;

    srand((unsigned) time(&t));
    ball = malloc(sizeof(ball_t));
    ball->pos_y = 2;
    ball->pos_x = 5;
    ball->xm = 0;
    ball->ym = 0;
    ball->y_vec = rand() % 2;
    ball->x_vec = rand() % 2;
    if (ball->y_vec == 0)
        ball->y_vec = -1;
    if (ball->x_vec == 0)
        ball->x_vec = -1;
    return ball;
}

int is_on_side(player_t *p, ball_t *ball)
{
    if ((ball->pos_y == p->pos_y + 1) ||
        (ball->pos_y == p->pos_y + 2) ||
        (ball->pos_y == p->pos_y + 3))
        return 1;
    return 0;
}

int is_ball_on_paddle(game_t *g)
{
    if (((g->ball->pos_y == g->p1->pos_y - 1) ||
        (g->ball->pos_y == g->p1->pos_y) ||
        (is_on_side(g->p1, g->ball) == 1)) &&
        g->ball->pos_x == g->p1->pos_x + 2)
        return 1;
    else if (((g->ball->pos_y == g->p2->pos_y - 1) ||
        (g->ball->pos_y == g->p2->pos_y) ||
        (is_on_side(g->p2, g->ball) == 1)) &&
        g->ball->pos_x == g->p2->pos_x - 1)
        return 1;
    return 0;
}

void reset_ball(game_t *g)
{
    g->ball->pos_x = (g->ball->xm) / 2;
    g->ball->pos_y = (g->ball->ym) / 2;
    g->ball->y_vec = rand() % 2;
    g->ball->x_vec = rand() % 2;
    if (g->ball->y_vec == 0)
        g->ball->y_vec = -1;
    if (g->ball->x_vec == 0)
        g->ball->x_vec = -1;
    timeout(-1);
    clear();
    disp_players_points(g);
    disp_mid_line(g);
    mvprintw(g->ball->pos_y, g->ball->pos_x, "o");
    disp_point_lim(g);
    reset_player_pos(g);
    disp_player(g->p1);
    disp_player(g->p2);
    refresh();
    getch();
    timeout(g->delay);
}

game_t *add_point(game_t *g)
{
    if (g->ball->pos_x <= 0) {
        g->p2->points += 1;
        g = win_screen(g);
        reset_ball(g);
    }
    if (g->ball->pos_x >= g->ball->xm) {
        g->p1->points += 1;
        g = win_screen(g);
        reset_ball(g);
    }
    return g;
}

game_t *move_ball(game_t *g)
{
    if (g->ball->pos_x <= 0 || g->ball->pos_x >= g->ball->xm)
        g = add_point(g);
    if (is_ball_on_paddle(g) == 1) {
        if (g->ball->x_vec == 2) {
            g->ball->x_vec -= 1;
            g->delay = 80;
        }
        else if (g->ball->x_vec == 1) {
            g->ball->x_vec += 1;
            g->delay = 100;
        }
        g->ball->x_vec *= -1;
    }
    if (g->ball->pos_y == 0 || g->ball->pos_y >= g->ball->ym - 1)
        g->ball->y_vec *= -1;
    mvprintw(g->ball->pos_y, g->ball->pos_x, "o");
    refresh();
    g->ball->pos_y = g->ball->pos_y + g->ball->y_vec;
    g->ball->pos_x = g->ball->pos_x + g->ball->x_vec;
    return g;
}

void init_ncurses(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
}