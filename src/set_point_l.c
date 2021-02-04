/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** set_point_l
*/

#include "my.h"

game_t *mod_point_l(char c, game_t *g)
{
    if (c == 'z' && g->point_l <= 19)
        g->point_l += 1;
    if (c == 's' && g->point_l > 1)
        g->point_l -= 1;
    return g;
}

void print_plus(game_t *g)
{
    mvprintw((g->ball->ym / 2) - 4, g->ball->xm / 2, "+");
    mvprintw((g->ball->ym / 2) - 4, (g->ball->xm / 2) - 8, "z  ->");
}

void print_minus(game_t *g)
{
    mvprintw((g->ball->ym / 2), (g->ball->xm / 2) - 8, "s  ->");
    mvprintw((g->ball->ym / 2), g->ball->xm / 2, "-");
}

void print_esc(game_t *g)
{
    clear();
    mvprintw((g->ball->ym / 2) - 2, (g->ball->xm / 2) - 6,
            "Thanks for playing !");
    refresh();
    sleep(2);
    endwin();
    exit(0);
}

void print_line(game_t *g)
{
    int i = 0;
    int y = 3;

    while (i <= g->ball->xm) {
        mvprintw(y, i, "=");
        i++;
    }
}

game_t *set_point_l(game_t *g)
{
    char c;

    g->point_l = 1;
    while (1) {
        clear();
        mvprintw(1, (g->ball->xm / 2) - 29, "Esc to exit");
        mvprintw(1, (g->ball->xm / 2) - 9, "POINT LIMIT");
        print_plus(g);
        print_line(g);
        mvprintw((g->ball->ym / 2) - 2, g->ball->xm / 2, "%d", g->point_l);
        mvprintw((g->ball->ym / 2) - 2, g->ball->xm / 2 + 2,
                    " point(s) to win (ENTER to confirm)");
        print_minus(g);
        c = getch();
        mod_point_l(c, g);
        if (c == 27)
            print_esc(g);
        if (c == 10)
            break;
    }
    return g;
}