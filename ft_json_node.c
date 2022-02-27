/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:33:43 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 10:47:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node* node_goto(json* data, str path)
{
	node* n = data->base_node->nx;
	node* r = data->base_node;
	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical_insensitive(n->name, *p))
		{
			r = n;
			if (*(p + 1) && n->nx)
			{
				n = n->nx;
				*p++;
			}
			else
				break ;
		}
		else
			n = n->dn;
	}

	if (r)
		logger(3, " # goto [ r: ", r->name, " ]");
	if (*p)
		logger(3, " # goto [ p: ", *p, " ]");
	if (n)
		logger(3, " # goto [ n: ", n->name, " ]");

	if (*(p + 1) || !ft_stridentical_insensitive(r->name, *p))
		r = 0;

	ft_strfree2d(splitpath);
	return r;
}

void nodelist_clear(node* n)
{
	if (!n)
		return ;
	free(n->name);
	free(n->value);
	nodelist_clear(n->nx);
	nodelist_clear(n->dn);
	free(n);
	return ;
}

void node_del(node* n)
{
	if (!n)
	{
		return ;
	}
	free(n->name);
	free(n->value);
	if (n->pv && n->nx)
	{
		n->pv->nx = n->nx;
		n->nx->pv = n->pv;
	}
	else if (n->pv && !n->nx)
		n->pv->nx = n->nx;
	node_del(n->nx);
	free(n);
	return ;
}

node* node_new(str name, str value, node* up, node* nx, node* dn, node* pv)
{
	logger(5, "  * node_nw, ", name, " '", value, "' will have:");
	logger(2, "\t\tup->", up ? up->name : "0");
	logger(4, "\tpv->", pv ? pv->name : "0", "\tnx->", nx ? nx->name : "0");
	logger(2, "\t\tdn->", dn ? dn->name : "0");
	node* nw = calloc(sizeof(node), 1);
	nw->name = name;
	nw->value = value;
	nw->up = up;
	nw->nx = nx;
	nw->dn = dn;
	nw->pv = pv;
	if (up && !dn && !up->dn)
		up->dn = nw;
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
		pv->nx = nw;
	logger_rose(nw);
	logger(3, "  * // ", name, ".");
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
