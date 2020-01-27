/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:02:59 by fde-capu          #+#    #+#             */
/* U20200127003613 |||:::                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*stc_skip_c(char *s, char c)
{
	while ((*s) && (*s == c))
		s++;
	return (s);
}

static int	stc_count(char *s, char c)
{
	int	n;

	n = 0;
	s = stc_skip_c((char *)s, c);
	if ((*s) && (*s != c))
		n++;
	while ((*s) && (*s != c))
		s++;
	return (*s ? n + stc_count(s, c) : n);
}

static int	stc_len(char *s, char c)
{
	int	n;

	n = 0;
	while ((*s) && (*s != c))
	{
		s++;
		n++;
	}
	return (n);
}

static int	stc_lgs(char *s, char c)
{
	int	max;
	int	len;

	max = 0;
	len = 0;
	while (*s)
	{
		s = stc_skip_c((char *)s, c);
		while ((*s) && (*s != c))
		{
			s++;
			len++;
		}
		max = len > max ? len : max;
	}
	return (max);
}

char		**ft_split(char const *s, char c)
{
	char	**spl;
	int		i;
	int		w;
	char	*r;

	r = (char *)s;
	r = stc_skip_c(r, c);
	spl = (char **)ft_calloc((stc_lgs(r, c) + 1), (stc_count(r, c) + 1));
	i = 0;
	while(*r)
	{
		spl[i] = (char *)malloc(stc_len(r, c) + 1);
		w = 0;
		while ((*r) && (*r != c))
		{
			spl[i][w] = *r;
			w++;
			r++;
		}
		i++;
		r = stc_skip_c(r, c);
	}
	return (spl);
}
