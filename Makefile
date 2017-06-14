##
## Makefile for Makefile in /home/SingeSumo/Epitech/PSU/PSU_2016_42sh
## 
## Made by SingeSumo
## Login   <SingeSumo@epitech.net>
## 
## Started on  Tue Apr 11 22:54:00 2017 SingeSumo
## Last update Fri Apr 21 19:57:49 2017 SingeSumo
##

GCC	=	gcc -g3 -o

NAME	=	42sh

TEST	=	Test/42sh

T_ON	=	

SRC	=	my_cd.c			\
		my_env.c		\
		my_ctrl.c		\
		my_exec.c		\
		my_exit.c		\
		my_free.c		\
		my_alloc.c		\
		my_error.c		\
		my_shell.c		\
		my_prompt.c		\
		my_parsing.c		\
		utils/my_gnl.c		\
		utils/my_disp.c		\
		utils/my_utils.c	\
		utils/my_wordtab.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I include

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

RM	=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(GCC) $(NAME) $^
#		$(GCC) $(TEST) $^

copy:
		cp -rf ../Test .

%.o:		%.c
		$(GCC) $@ $(INC) $(CFLAGS) -c $^

clean:
		find . -name '*~' -delete -o -name  '#*#' -type f -delete -o -name "*.o" -delete

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
