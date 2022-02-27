/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 11:37:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
	logger(3, "Try to put ", path, ".");

	if (ft_strstr("=", path))
		return json_post(data, path);

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

	if (r) logger(2, " # r ", r->name);
	if (*p) logger(2, " # p ", *p);
	if (n) logger(2, " # n ", n->name);

	if (ft_stridentical(r->name, *p))
	{
		if (!*(p + 1))
		{
			ft_strfree2d(splitpath);
			logger(1, " Nothing to do.");
			return json_render_node(r, 0, 0);
		}
		*p++;
	}

	while (*p)
	{
		logger(7, " ", r->name, " - followed to ", *p, " in ", path, ".");
		if (!r->nx)
		{
			logger(5, " # ", r->name, " is last, from here create ", *(p + 0), ".");
			r->nx = node_new(ft_strdup(*(p + 0)), 0, 0, 0, 0, r);
			r = r->nx;
			*p++;
		}
		else
		{
			logger(5, " # ", r->name, "->nx is ", r->nx->name, ".");
			node *x = node_last_dn(r->nx);
			logger(7, " Can put ", *p, " below ", x->name, ", pv to ", r->name, ".");
			x->dn = node_new(ft_strdup(*p), 0, x, 0, 0, r);
			r = x->dn;
			*p++;
		}
//		*p++;
	}

	ft_strfree2d(splitpath);
	logger(3, "/Try: put ", r->name, ".");
	return json_render_node(r, 0, 0);
}

str json_post(json* data, str path)
{
	logger(3, "Try to post ", path, ".");
	str* chain = ft_split_set(path, "=,");
	str foo = json_put(data, chain[0]);
	json_render(data);
	logger(3, "Keep posting. Now try ", chain[0], ".");
	free(foo);
	node *h = node_goto(data, chain[0]);
	if (!h)
	{
		logger(3, "Did not find ", chain[0], ".");
		ft_strfree2d(chain);
		return 0;
	}
	logger(2, "Can post as a child of ", h->name);
	h->value = ft_x(h->value, correct_quotes(chain[1]));
	ft_strfree2d(chain);
	return json_render_node(h->pv, 0, 1);
}

str json_del(json* data, str path)
{
	logger(3, "Try del ", path, ".");
	str path_no_reserved = no_reserved(path);
	if (ft_stridentical(path, path_no_reserved))
	{
		node *h = node_goto(data, path);
		free(path_no_reserved);
		if (!h)
		{
			logger(3, " Could not go to ", path, ". Die.");
			return 0;
		}
//		logger_rose(h);
//		if(!h->up)
//		{
//			h->pv->nx = h->dn;
//			node_del(h);
//		}

		logger(2, "//del ", h->name);
		return json_render_node(h, 0, 0);
	}
	else
	{
		logger(3, "Will use ", path_no_reserved, " instead.");
		node *h = node_goto(data, path_no_reserved);
		free(path_no_reserved);
		if (!h)
			return 0;
		free(h->value);
		h->value = 0;
		return json_render_node(h, 0, 0);
	}
}
