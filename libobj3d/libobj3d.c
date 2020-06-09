/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libobj3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:06:03 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/18 16:27:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj3d.h"

void	init_obj3d(void)
{
	g_gravity = 9.807;
	g_ease_out = bez_cub_feed(0, 0, .18, .84, .76, 1, 1, 1);
}

void	vtxcpy(t_vertex *dst, t_vertex *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	return ;
}

void	vctcpy(t_vector *dst, t_vector *src)
{
	vtxcpy(dst->base, src->base);
	vtxcpy(dst->head, src->head);
	return ;
}

void	objcpy(t_obj_3d *dst, t_obj_3d *src)
{
	vtxcpy(dst->pos, src->pos);
	vctcpy(dst->spd, src->spd);
	vctcpy(dst->smx, src->smx);
	vctcpy(dst->acl, src->acl);
	vctcpy(dst->res, src->res);
	return ;
}

t_vertex	vctlen(t_vector v)
{
	t_vertex	vr;

	vr.x = v.head.x - v.base.x;
	vr.y = v.head.y - v.base.y;
	vr.z = v.head.z - v.base.z;
	return (vr);
}
