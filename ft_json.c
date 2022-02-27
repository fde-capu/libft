/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 12:31:16 by fde-capu         ###   ########.fr       */
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
	if (ft_strstr("=", path))
		return json_post(data, path);

	logger(2, "\\ put ", path);

	str* splitpath = path_split(path);
	str* h_path = splitpath;
	node* h = data->base_node->nx;
	node* ret = data->base_node;

	while (h)
	{
		if (ft_stridentical_insensitive(h->name, *h_path))
		{
			ret = h;
			if (*(h_path + 1) && h->nx)
			{
				h = h->nx;
				*h_path++;
			}
			else
				break ;
		}
		else
			h = h->dn;
	}

	if (!*(h_path + 1) && ret != data->base_node)
	{
		ft_strfree2d(splitpath);
		logger(1, " Nothing to do.");
		return json_render_node(ret, 0, 0);
	}

	if (ret) logger(2, " - ret ", ret->name);
	if (*h_path) logger(2, " - h_path ", *h_path);
	if (h) logger(2, " - h ", h->name);

	node *up = 0;
	node *nx = 0;
	node *dn = 0;
	node *pv = 0;

	while (*++h_path || (*--h_path && ret == data->base_node))
	{
		logger(4, " # ", ret->name, "->", *h_path);
		pv = ret;
		if (ret->nx)
			up = node_last_dn(ret->nx);
		ret = node_new(ft_strdup(*h_path), 0, up, nx, dn, pv);
	}

	logger_rose(ret);

	ft_strfree2d(splitpath);
	logger(1, "/");
	return json_render_node(ret, 0, 0);
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
