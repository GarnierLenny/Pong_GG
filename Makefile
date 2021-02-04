##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make
##

SRC		=	src/ball_man.c\
			src/player.c\
			src/usage.c\
			src/print_misc.c\
			src/win_screen.c\
			src/init_g.c\
			src/game_loop.c\
			src/set_point_l.c\

SRC_M	=	src/main.c

SRC_UT	=	tests/*.c

OBJ		=	$(SRC:.c=.o)

OBJ_M	=	$(SRC_M:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

INCLUDE	=	-I./include

NAME	=	pong_GG

NAME_UT	=	unit_tests

CFLAGS	=	-W -Werror -Wall -Wextra -I./include -lncurses

CFLAGS_UT	=	-lcriterion --coverage -lgcov

LIB		=	-L lib/ -lmy

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ_M) $(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(OBJ_M) $(INCLUDE) $(CFLAGS) $(LIB)

tests_run:	$(OBJ) $(OBJ_UT)
		make -C lib/my/
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(INCLUDE) $(CFLAGS_UT) $(LIB)
		./$(NAME_UT)
		gcovr -e tests

clean:
		$(RM) $(OBJ) $(OBJ_M) lib/my/*.o lib/libmy.a lib/my/libmy.a *gcno *gcda *~

fclean:		clean fclean_ut
		$(RM) $(NAME) tests/*.o

fclean_ut: clean
		$(RM) $(NAME_UT)

re:		fclean all