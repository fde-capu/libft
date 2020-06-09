/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:39:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/18 16:15:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj3d.h"

double		timep(t_movemn m)
{
	double	p;

	p = m.elap / m.time;
	p = p >= 1 ? 1 : p;
	return (p);
}

t_vector	ease_not(t_movemt m)
{
	double		p;
	double		x;
	double		y;
	double		z;
	t_vector	v;

	p = timep(m);
	v.base.x = m.path.base.x + ((m.path.head.x - m.path.base.x) * p);
	v.base.y = m.path.base.y + ((m.path.head.y - m.path.base.y) * p);
	v.base.z = m.path.base.z + ((m.path.head.z - m.path.base.z) * p);
	return (v);
}

t_vector	ease_out(t_movemt m)
{
	double		p;
	t_point		f;
	t_vector	v;

	p = timep(m);
	f = cubic_bez(g_ease_out, p);
	v.base.x = m.path.base.x + ((m.path.head.x - m.path.base.x) * f);
	v.base.y = m.path.base.y + ((m.path.head.y - m.path.base.y) * f);
	v.base.z = m.path.base.z + ((m.path.head.z - m.path.base.z) * f);
	return (v);
}
