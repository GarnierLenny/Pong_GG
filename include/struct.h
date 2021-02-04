/*
** EPITECH PROJECT, 2020
** ncurses_test
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct ball_s {
    int pos_x;
    int pos_y;
    int xm;
    int ym;
    int y_vec;
    int x_vec;
} ball_t;

typedef struct player_s {
    int pos_x;
    int pos_y;
    int ymin;
    int ymax;
    int vel;
    int points;
} player_t;

typedef struct game_s {
    ball_t *ball;
    player_t *p1;
    player_t *p2;
    int point_l;
    int delay;
} game_t;

#endif /* !STRUCT_H_ */