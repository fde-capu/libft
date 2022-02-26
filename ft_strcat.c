/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:18:03 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/26 20:00:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(const char *dst, const char *src)
{
	char	*ret;
	char	*r;
	char	*w;

	ret = ft_calloc(ft_strlen(dst) + ft_strlen(src) + 1, 1);
	r = (char *)dst;
	w = (char *)ret;
	while ((r) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	r = (char *)src;
	while ((r) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	return (ret);
}

char	*ft_strcatxl(char *s1, char *s2)
{
	char	*x;

	x = ft_strcat(s1, s2);
	if (s1)
		free(s1);
	return (x);
}

char	*ft_strcatxr(char *s1, char *s2)
{
	char	*x;

	x = ft_strcat(s1, s2);
	free(s2);
	return (x);
}

char	*ft_strcatxx(char *s1, char *s2)
{
	char	*x;

	x = ft_strcat(s1, s2);
	free(s1);
	free(s2);
	return (x);
}

str		ft_strcat_variadic(int argc, ...)
{
	va_list h;
	va_start(h, argc);
	str out = ft_str("");
	while (argc--)
		out = ft_x(out, ft_strcat(out, va_arg(h, char *)));
	va_end(h);
	return out;
}
