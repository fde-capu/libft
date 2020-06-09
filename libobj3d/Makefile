# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/18 16:51:00 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/18 18:53:51 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libobj3d.a

GCC		=	gcc -Wall -Werror -Wextra

AR		=	ar -rcs

SRC		=	$(shell find . -name '*.c')	

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(AR) $(NAME) $(OBJ)	

$(SRC)	:
	$(GCC) -o $(OBJ) -c $(SRC)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all
