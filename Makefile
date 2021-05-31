##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## root push_swap
##

SRC	=	main.c	\
		navy.c

NAME	=	navy

KILL_IT =	kill_it

all:	$(NAME) clean

libmy:
	@make -sC lib/my/

$(NAME):	libmy
	@gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy -g
	@echo -e "\033[05m\033[32mCompilation done => ${NAME}\033[00m"

kill_it:	libmy
	@gcc -o $(KILL_IT) kill_it.c -I./include -L./lib -lmy
	@echo -e "\033[05m\033[32mCompilation done => ${KILL_IT}\033[00m"

clean:
	make -sC lib/my/ clean
	rm -f *~ include/*~ lib/my/*~ tests/*~

fclean:	clean
	make -sC lib/my/ fclean
	rm -f $(NAME)
	rm -f $(KILL_IT)
	rm -f game_board_*
	clear

re:	fclean all
