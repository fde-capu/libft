/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:02:59 by fde-capu          #+#    #+#             */
/* U20200126201843 ||::|:                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*stc_skip_c(char *s, char c)
{
	while ((*s) && (*s == c))
		s++;
	return (s);
}

static int	stc_word_count(char *s, char c)
{
	int	n;

	n = 0;
	s = stc_skip_c(s, c);
	if ((*s) && (*s != c))
		n++;
	while ((*s) && (*s != c))
		s++;
	return (*s ? n + stc_word_count(s, c) : n);
}

static int	stc_word_len(char *s, char c)
{
	int	n;

	n = 0;
//	printf("len: %s --", s);
	while ((*s) && (*s != c))
	{
		s++;
		n++;
	}
//	printf(" %d\n", n);
	return (n);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;
	char	*z;
	char	*w;
	int		i;

		//printf("Anal: --%s-- ", s);
	word_count = stc_word_count((char *)s, c);
		//printf("WC %d\n", word_count);
	split = (char **)malloc(sizeof(char) * (word_count + 1));
		printf("==========\nsplit alloc %d\n", word_count + 1);
	z = (char *)s;
	z = stc_skip_c(z, c);
	i = 0;
	while (*z)
	{
		w = (char *)malloc(sizeof(char) * (stc_word_len(z, c) + 1));
		printf("split[%d] alloc %d\n", i, (stc_word_len(z, c) + 1));
		*(split + i) = w;
		while ((*z) && (*z != c))
		{
//			*w = *z;
//			w++;
			z++;
		}
//		*w = '\0';
		//printf("split[%d] %s\n", i, split[i]);
		i++;
		z = stc_skip_c(z, c);
	}
//	split[i] = NULL;
		//printf("split[%d] %s\n", i, split[i]);
	return (split);
}
