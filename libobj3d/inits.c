/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:16:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/18 16:12:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj3d.h"

t_vertex	*init_vertex(double x, double y, double z)
{
	t_vertex	*m;

	if (!(m = malloc(sizeof(t_vertex))))
		return (NULL);
	m->x = x;
	m->y = y;
	m->z = z;
	return (m);
}

t_vector	*init_vector(t_vertex base, t_vertex head)
{
	t_vector	*m;

	if (!(m = malloc(sizeof(t_vector))))
		return (NULL);
	vtxcpy(m->base, base);
	vtxcpy(m->head, head);
	return (m);
}

t_obj_3d	*init_obj_3d(t_vertex pos)
{
	t_obj_3d	*m;

	if (!(m = malloc(sizeof(t_obj_3d))))
		return (NULL);
	vtxcpy(m->pos, pos);
	return (m);
}

t_player	*init_player(t_obj_3d conf, t_vector face, t_vector weig)
{
	t_player	*p;
	
	if (!(p = ft_malloc(sizeof(t_player), 1)))
		return (NULL);
	objcpy(&p->obj, conf);
	vctcpy(&p->fac, face);
	vctcpy(&p->wei, weig);
	return (p);
}

t_movemt	init_movemt(void)
{
	t_movemt	*m;

	m = ft_calloc(sizeof(t_movemt), 1);
	return (m);
}
