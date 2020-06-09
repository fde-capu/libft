/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tik.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:37:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/18 16:46:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj3d.h"

void		objtik(t_obj_3d *obj, double time)
{
	double		tf;

	tf = time / 1000;
	obj->spd.x += obj->acl.x * tf; 
	obj->spd.y += obj->acl.y * tf;
	obj->spd.z += obj->acl.z * tf;
	obj->spd.x += obj->res.x * tf;
	obj->spd.y += obj->res.y * tf;
	obj->spd.z += obj->res.z * tf;
	obj->spd.x = obj->spd.x > obj->smx.x ? obj->smx.x : obj->spd.x;
	obj->spd.y = obj->spd.y > obj->smx.y ? obj->smx.y : obj->spd.y;
	obj->spd.z = obj->spd.z > obj->smx.z ? obj->smx.z : obj->spd.z;
	obj->pos.x += obj->spd.x * tf;
	obj->pos.y += obj->spd.y * tf;
	obj->pos.z += obj->spd.z * tf;
	return ;
}

void		plrtik(t_player *plr, double time)
{
	if (plr->obj.pos.z > plr->hei)
	{
		plr->obj.acl.z = -g_gravity;
		plr->obj.pos.z = plr->obj.pos.z < plr->hei ? plr->hei : plr->obj.pos.z;
		plr->obj.acl.z = plr->obj.pos.z == plr->hei ? 0 : plr->obj.acl.z;
	}
	objtik(&plr->obj, time);
	return ;
}
