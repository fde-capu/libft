# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 14:30:12 by fde-capu          #+#    #+#              #
#    Updated: 2020/02/03 14:21:51 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

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
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c		\
		ft_split.c			\
		ft_strmapi.c

BSRCS = ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_strcmp_bonus.c	\
		ft_strcpy_bonus.c

OBJS =	$(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

all :	$(NAME)

$(SRCS) :
	$(CC) -o $(OBJS) -c $(SRCS) $(FLAGS) 

$(BSRCS) :
	$(CC) -o $(OBJS) -c $(BRCS) $(FLAGS) 

$(NAME) :	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

bonus:	all $(BOBJS)
	$(AR) $(NAME) $(OBJS) $(BOBJS)
