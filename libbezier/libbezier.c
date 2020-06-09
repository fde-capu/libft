/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbezier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:21:14 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 12:30:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbezier.h"

t_d2d		linint(t_d2d a, t_d2d b, double t)
{
	t_d2d	p;

	p.x = (a.x + ((b.x - a.x) * t));
	p.y = (a.y + ((b.y - a.y) * t));
	return (p);
}

t_d2d		cubic_bez(t_cub_bez bez, double t)
{
	t_d2d	p[6];

	p[0] = linint(bez.a, bez.b, t);
	p[1] = linint(bez.b, bez.c, t);
	p[2] = linint(bez.c, bez.d, t);
	p[3] = linint(p[0], p[1], t);
	p[4] = linint(p[1], p[2], t);
	p[5] = linint(p[3], p[4], t);
	return (p[5]);
}

t_cub_bez	bez_cub_feed(double ax, double ay, double bx, double by, \
	double cx, double cy, double dx, double dy)
{
	t_cub_bez	f;
	f.a.x = ax;
	f.a.y = ay;
	f.b.x = bx;
	f.b.y = by;
	f.c.x = cx;
	f.c.y = cy;
	f.d.x = dx;
	f.d.y = dy;
	return (f);
}
