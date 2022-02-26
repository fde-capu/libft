/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/26 02:04:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

str* path_split(str path)
{
	return ft_split(path, '/');
}

node* node_goto(json* data, str path)
{
	node* n = data->base_node->nx;
	node* r = data->base_node;

	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical(n->name, *p))
		{
			r = n;
			if (*(p + 1))
			{
				if (n->nx)
				{
					n = n->nx;
					*p++;
				}
				else
					break ;
			}
			else
				break ;
		}
		else
			n = n->dn;
	}
//	if (r)
//		printf("r: %s\n", r->name);
//	if (*p)
//		printf("p: %s\n", *p);
//	if (n)
//		printf("n: %s\n", n->name);
	if (*(p + 1) || !ft_stridentical(r->name, *p))
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

node* node_new()
{
	node* out = calloc(sizeof(node), 1);
	return out;
}

node* node_last_dn(node* h)
{
	return !h ? 0 : h->dn ? node_last_dn(h->dn) : h;
}

node* node_last_nx(node* h)
{
	return !h ? 0 : h->nx ? node_last_nx(h->nx) : h;
}

str json_put(json* data, str path)
{
	node* b = data->base_node;
	node* n = data->base_node->nx;
	node* x;
	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical(n->name, *p))
		{
			b = n;
			if (*(p + 1))
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
	while (*p)
	{
		x = node_last_nx(b->nx);
		if (!x)
		{
			b->nx = node_new();
			b->nx->pv = b;
			b->nx->name = ft_strdup(*p);
			b = b->nx;
		}
		else
		{
			x->dn = node_new();
			x->dn->up = x;
			x->dn->name = ft_strdup(*p);
			b = x->dn;
		}
		*p++;
	}
	ft_strfree2d(splitpath);
	return ft_strdup(b->name);
}

str json_del(json* data, str path)
{
	node *h = node_goto(data, path);
	if (!h)
		return 0;
	h = h->pv;
	node* nxnx = h->nx->dn;
	node_del(h->nx);
	h->nx = nxnx;
	h->nx->pv = h->nx;
	return ft_strdup(h->name);
}

json* json_new()
{
	json* new_json = calloc(sizeof(json), 1);
	new_json->base_node = node_new();
	new_json->base_node->name = ft_str("baseNode");
	return new_json;
}

void json_clear(json *this)
{
	nodelist_clear(this->base_node);
	free(this);
	return ;
}

str json_render_node(node* h)
{
	if (!h)
		return 0;
	str index = ft_itoa(h->index);
	str out = ft_strcat_variadic(5, "'", h->name, "' : { 'index' : ", index, " , ");
	free(index);
	if (h->value)
		out = ft_strcat_variadic(3, "'value' : '", h->value, "' , ");
	if (h->nx)
		out = ft_strcatxx(out, json_render_node(h->nx));
	out = ft_strcatxl(out, "} , ");
	return out;
//	return ft_strcatxx(out, json_render_node(h->dn));
}

str	json_get(json* data, str path)
{
	str out = 0;
	node* h = node_goto(data, path);
	if (h)
		out = json_render_node(h);
	return out;
}

str json_render(json* data)
{
	str out = json_render_node(data->base_node->nx);
	printf("%s\n\n", out);
	if (out)
		free(out);
	return 0;
}
