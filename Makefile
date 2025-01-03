# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 11:38:47 by fde-capu          #+#    #+#              #
#    Updated: 2022/02/27 19:25:08 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef OUTPUT
.SILENT:
endif

NAME	=	libft.a
SRCS	=	$(shell find . -name '*.c' ! -name "main.c")
HEAD	=	$(shell find . -name '*.h') Makefile
SHELL	=	/bin/sh
CC		=	cc
CCFLAGS	=	-Wall -Wextra -Werror -g
AR		=	ar -rcs
CHILD	=	libbezier
OBJS	=	$(SRCS:.c=.o)
ELINE	=	echo	""; echo ""
LINE	=	echo	"================== from $(NAME) ==============================================="
PUTS	=	echo	
T0		=	$(ELINE); $(LINE); $(PUTS)
T2		=	; $(LINE)
VAL		=	valgrind
VALFLAG	=	--tool=memcheck \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--show-reachable=yes

all		:	$(CHILD) $(NAME)
$(CHILD) :
	cd $(CHILD) && $(MAKE) && cd -
$(NAME)	:	$(OBJS)
	$(AR) $(NAME) $(OBJS)
$(OBJS)  : %.o : %.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<
clean	:
	rm -f $(OBJS)
fclean	:	clean
	rm -f $(NAME)
re		:	fclean all
t		:	all
	$(CC) $(CCFLAGS) main.c -L. -lft
	$(VAL) $(VALFLAG) ./a.out
