/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:33:43 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 19:26:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node* node_goto(json* data, str path)
{
	node* nd = data->base_node->nx;
	node* ret = data->base_node;
	str* splitpath = path_split(path);
	str* h_path = splitpath;

	while (nd)
	{
		if (ft_stridentical_insensitive(nd->name, *h_path))
		{
			ret = nd;
			if (*(h_path + 1) && nd->nx)
			{
				nd = nd->nx;
				*h_path++;
			}
			else
				break ;
		}
		else
			nd = nd->dn;
	}

//	if (ret)
//		logger(3, " # goto [ ret: ", ret->name, " ]");
//	if (*h_path)
//		logger(3, " # goto [ h_path: ", *h_path, " ]");
//	if (nd)
//		logger(3, " # goto [ nd: ", nd->name, " ]");

	if (*(h_path + 1) || !ft_stridentical_insensitive(ret->name, *h_path))
		ret = 0;

	ft_strfree2d(splitpath);
	return ret;
}

void nodelist_clear(node* nd)
{
	if (!nd)
		return ;
	free(nd->name);
	free(nd->value);
	nodelist_clear(nd->nx);
	nodelist_clear(nd->dn);
	free(nd);
	return ;
}

void node_del(node* nd)
{
	if (!nd)
	{
		logger(1, "  |- 0");
		return ;
	}

	while (nd->nx)
		node_del(nd->nx);

	logger(2, "  |- ", nd->name);
	
	if (nd->up)
	{
		nd->up->dn = nd->dn;
	}
	else
	{
		nd->pv->nx = nd->dn ? nd->dn : nd->nx;
		if (nd->pv->nx)
			nd->pv->nx->up = 0;
	}

	free(nd->name);
	free(nd->value);
	free(nd);
	return ;
}

node* node_new(str name, str value, node* up, node* nx, node* dn, node* pv)
{
	logger(5, "   |+ ", name, " : '", value, "'");
	node* nw = calloc(sizeof(node), 1);
	nw->name = name;
	nw->value = value;
	nw->up = up;
	nw->nx = nx;
	nw->dn = dn;
	nw->pv = pv;
	if (up && !dn && !up->dn)
	{
		up->dn = nw;
	}
	if (nx && pv && nx->pv == pv && pv->nx == nx)
	{
		pv->nx = nw;
		nx->pv = nw;
	}
	if (dn && up && dn->up == up && up->dn == dn)
	{
		up->dn = nw;
		dn->up = nw;
	}
	if (pv && !pv->nx)
	{
		pv->nx = nw;
	}
	return nw;
}

node* node_last_dn(node* h)
{
	return !h ? 0 : h->dn ? node_last_dn(h->dn) : h;
}

node* node_last_nx(node* h)
{
	return !h ? 0 : h->nx ? node_last_nx(h->nx) : h;
}
