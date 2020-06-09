/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:30:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 15:32:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_rgb(unsigned char r, unsigned char b, unsigned char g)
{
	t_rgb	o;

	o.r = r;
	o.g = g;
	o.b = b;
	return (o);
}

t_rgb	ft_atorgb(char *str)
{
	char			**rgb;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	rgb = ft_split(str, ',');
	r = (unsigned char)ft_atoi(rgb[0]);
	g = (unsigned char)ft_atoi(rgb[1]);
	b = (unsigned char)ft_atoi(rgb[2]);
	ft_strfree2d(rgb);
	return (ft_rgb(r, g, b));
}

char	*ft_rgbtoa(t_rgb rgb)
{
	char	*o;

	o = ft_uctoa(rgb.r);
	o = ft_strcatxl(o, DIV);
	o = ft_strcatxl(o, ft_uctoa(rgb.g));
	o = ft_strcatxl(o, DIV);
	o = ft_strcatxl(o, ft_uctoa(rgb.b));
	return (o);
}
