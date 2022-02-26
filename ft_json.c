/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 23:42:15 by fde-capu         ###   ########.fr       */
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

node* node_goto_before_last(json *data, str path)
{
	node* n = data->base_node->nx;
	node* b = data->base_node;
	node* o = b;
	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical(n->name, *p))
		{
			o = b;
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
	ft_strfree2d(splitpath);
	return o;
}

void nodelist_free(node* n)
{
	if (!n)
		return ;
	if (n->dn)
		nodelist_free(n->dn);
	nodelist_free(n->nx);
	free(n->name);
	free(n->value);
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
	node* n = data->base_node->nx;
	node* b = data->base_node;
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
			b->nx->name = ft_strdup(*p);
			b = b->nx;
		}
		else
		{
			x->dn = node_new();
			x->dn->name = ft_strdup(*p);
			b = x->dn;
		}
		*p++;
	}
	ft_strfree2d(splitpath);
	return ft_strdup(b->name);
}

str	json_get(json* data, str path)
{
	str out = 0;
	node* h = node_goto(data, path);
	if (h)
		out = ft_strdup(h->name);
	return out;
}

str json_del(json* data, str path)
{
	node* h = node_goto(data, path);
	if (!h)
		return 0;
	h = node_goto_before_last(data, path);
	nodelist_free(h->nx);
	h->nx = 0;
	return ft_strdup(h->name);
}

json* json_new()
{
	json* new_json = calloc(sizeof(json), 1);
	new_json->base_node = node_new();
	new_json->base_node->name = ft_str("baseNode");
	return new_json;
}

void json_clean(json *this)
{
	nodelist_free(this->base_node);
	free(this);
	return ;
}

str json_render_node(node* h)
{
	if (!h)
	{
		return 0;
	}
	printf("%s = { ", h->name);
	printf("index: %d, ", h->index);
	if (h->value)
		printf("value: \"%s\", ", h->value);
	if (h->nx)
		json_render_node(h->nx);
	printf("}, ");
	json_render_node(h->dn);
}

str json_render(json* data)
{
	return json_render_node(data->base_node->nx);
}
