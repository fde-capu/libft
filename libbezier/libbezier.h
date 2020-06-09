/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbezier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:16:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/18 16:50:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBEZIER_H
# define LIBBEZIER_H

# include "../libft.h"

typedef	struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef	struct	s_cubic_bezier
{
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;
}				t_cub_bez;

t_point		linint(t_point a, t_point b, double t);
t_point		cubic_bez(t_cub_bez bez, double t);
t_cub_bez	bez_cub_feed(double ax, double ay, double bx, double by, \
	double cx, double cy, double dx, double dy);

#endif
