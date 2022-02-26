/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/26 18:57:19 by fde-capu         ###   ########.fr       */
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
		if (ft_stridentical_insensitive(n->name, *p))
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
//		printf("\n#[ r: %s ]", r->name);
//	if (*p)
//		printf("\n#[ p: %s ]", *p);
//	if (n)
//		printf("\n#[ n: %s ]", n->name);

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
	node* out = calloc(sizeof(node), 1);
	out->name = name;
	out->value = value;
	out->up = up;
//	if (up)
//		up->dn = out;
	out->nx = nx;
//	if (nx)
//		nx->pv = out;
	out->dn = dn;
//	if (dn)
//		dn->up = out;
	out->pv = pv;
//	if (pv)
//		pv->nx = out;
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

json* json_new()
{
	json* new_json = calloc(sizeof(json), 1);
	new_json->base_node = node_new(ft_str("baseNode"), 0, 0, 0, 0, 0);
	return new_json;
}

void json_clear(json *this)
{
	nodelist_clear(this->base_node);
	free(this);
	return ;
}

str json_render_as_attr(node* h)
{
	return ft_strcat_variadic(5, "'", h->name, "' : ", h->value, " , ");
}

str json_render_node(node* h, int go_dn, int show_name)
{
	if (!h)
		return 0;
	if (h->value && !h->nx)
		return json_render_as_attr(h);
	str out = show_name ?
		ft_strcat_variadic(3, "'", h->name, "' : { ")
		: ft_str("{ ");
	if (h->value)
		out = ft_x(out, ft_strcat_variadic(4, out, "'value' : ", h->value, " , "));
	if (h->nx)
		out = ft_strcatxx(out, json_render_node(h->nx, 1, 1));
	out = ft_strcatxl(out, "} , ");
	if (go_dn && h->dn)
		out = ft_strcatxx(out, json_render_node(h->dn, 1, 1));
	return out;
}

str json_render(json* data)
{
	str out = json_render_node(data->base_node->nx, 1, 1);
	printf("%s\n\n", out);
	if (out)
		free(out);
	return 0;
}

str	json_get(json* data, str path)
{
	str out = 0;
	node* h = node_goto(data, path);
	if (h)
		out = json_render_node(h, 0, 0);
	return out;
}

str json_put(json* data, str path)
{
	if (ft_strstr("=", path))
		return json_post(data, path);
	node* b = data->base_node;
	node* n = data->base_node->nx;
	node* x;
	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical_insensitive(n->name, *p))
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
	if (ft_stridentical_insensitive(b->name, *p))
	{
		ft_strfree2d(splitpath);
		return 0;
	}
	while (*p)
	{
		if (!b->nx)
		{
			b->nx = node_new(ft_strdup(*p), 0, 0, 0, 0, b);
//			b->nx->pv = b;
//			b->nx->name = ft_strdup(*p);
			b = b->nx;
		}
		else
		{
			x = node_last_nx(b->nx);
			x->dn = node_new(ft_strdup(*p), 0, x, 0, 0, 0);
//			x->dn->up = x;
//			x->dn->name = ft_strdup(*p);
			b = x->dn;
		}
		*p++;
	}
	ft_strfree2d(splitpath);
	return json_render_node(b, 0, 0);
}

str json_post(json* data, str path)
{
	str* chain = ft_split_set(path, "=;");
	node *h = node_goto(data, chain[0]);
	if (!h)
	{
		str foo = json_put(data, chain[0]);
		free(foo);
		node *h = node_goto(data, chain[0]);
	}
	if (!h)
	{
		ft_strfree2d(chain);
		return 0;
	}
	if (h->value)
		free(h->value);
	h->value = ft_strdup(chain[1]);
	ft_strfree2d(chain);
	return json_render_node(h->pv, 0, 0);
}

str no_reserved(str path)
{
	char * h = ft_strnstr(path, "value", ft_strlen(path));
	return h > path ? ft_substr(path, 0, h - path) : ft_strdup(path);
}

str json_del(json* data, str path)
{
	str path_no_reserved = no_reserved(path);
	if (ft_stridentical(path, path_no_reserved))
	{
		node *h = node_goto(data, path);
		free(path_no_reserved);
		if (!h)
			return 0;
		//	printf("1"); fflush(stdout);
		h = h->pv;
		//	printf("2"); fflush(stdout);
		node* nxnx = h->nx ? h->nx->dn : 0;
		//	printf("3"); fflush(stdout);
		node_del(h->nx);
		//	printf("4"); fflush(stdout);
		h->nx = nxnx;
		//	printf("5"); fflush(stdout);
		if (h->nx)
			h->nx->pv = h;
		//	printf("6"); fflush(stdout);
		return json_render_node(h, 0, 0);
	}
	else
	{
		node *h = node_goto(data, path_no_reserved);
		free(path_no_reserved);
		if (!h)
			return 0;
		free(h->value);
		h->value = 0;
		return json_render_node(h, 0, 0);
	}
}
