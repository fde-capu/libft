# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 14:30:12 by fde-capu          #+#    #+#              #
#    Updated: 2020/02/10 07:19:16 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	$(GCC) $(FLAGS) 

GCC =	gcc

FLAGS =	-Wall -Wextra -Werror

AR =	ar -rc

NAME =	libft.a

SRCS =	ft_memset.c			\
		ft_bzero.c			\
		ft_memmove.c		\
		ft_strlen.c			\
		ft_strlcpy.c		\
		ft_memchr.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_strnstr.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_isascii.c		\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_strjoin.c		\
		ft_substr.c			\
		ft_strtrim.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_isalnum.c		\
		ft_isprint.c		\
		ft_memcmp.c			\
		ft_strdup.c			\
		ft_strlcat.c		\
		ft_strncmp.c		\
		ft_tolower.c		\
		ft_toupper.c		\
		ft_putchar_fd.c		\
		ft_itoa.c			\
		ft_uitoa.c			\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c		\
		ft_split.c			\
		ft_strmapi.c		\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_strcmp.c			\
		ft_strcpy.c			\
		ft_ltoh.c			\
		ft_chrinset.c		\
		ft_whichar.c

OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

$(SRCS) :
	$(GCC) -o $(OBJS) -c $(SRCS) $(FLAGS) 

$(NAME) :	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all
