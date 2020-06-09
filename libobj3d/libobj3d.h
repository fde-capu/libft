/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libobj3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:06:00 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/18 16:49:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCTRLS_H
# define LIBCTRLS_H

# include "../libft.h"
# include "../libbezier/libbezier.h"

typedef	struct	s_vertex
{
	double		x;
	double		y;
	double		z;
}				t_vertex

typedef	struct	s_vector
{
	t_vertex	base;
	t_vertex	head;
}				t_vector;

typedef struct	s_obj_3d
{
	t_vertex	pos;
	t_vertex	spd;
	t_vertex	smx;
	t_vertex	acl;
	t_vertex	res;
}				t_obj_3d;

typedef	struct	s_player
{
	t_obj_3d	obj;		
	t_vertex	fac;
	t_vertex	wei;
	double		hei;
}				t_player;

typedef	struct	s_world;
{
	t_vector	gravity;
}				t_world;

typedef	struct	s_movemt
{
	t_vector	path;
	double		time;
	double		elap;
	void		(*ease)(struct s_movemt *);
}				t_movemt;

t_vertex	init_vertex(void);
t_vector	init_vector(void);

void		objtik(t_obj_3d *obj, double time);
void		plrtik(t_player *plr, double time);

t_vertex	ease_not(t_vertex ori, t_vertex dst, double time);
t_vertex	ease_out(t_vertex ori, t_vertex dst, double time);

t_cub_bez	g_ease_out;
double		g_gravity;

#endif
