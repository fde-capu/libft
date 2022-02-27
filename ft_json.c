/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 20:13:47 by fde-capu         ###   ########.fr       */
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
	node* ret = data->base_node;
	node* nd = data->base_node->nx;

	while (nd)
	{
		logger(4, " ? ", nd->name, " - ", *h_path);
		if (ft_stridentical_insensitive(nd->name, *h_path))
		{
			ret = nd;
			nd = nd->nx;
			*h_path++;
		}
		else
			nd = nd->dn;
	}
	
//	logger(4, " -c ", nd->name, " (->) ", *h_path);

//	if (!*(h_path + 1) && ret != data->base_node)
//	{
//		ft_strfree2d(splitpath);
//		logger(1, " Nothing to do.");
//		return json_render_node(ret, 0, 0);
//	}

	if (ret) logger(2, " - ret ", ret->name);
	if (*h_path) logger(2, " - h_path ", *h_path);
	if (nd) logger(2, " - nd ", nd->name);

	node *up = 0;
	node *nx = 0;
	node *dn = 0;
	node *pv = 0;

//	if (ret == data->base_node)
		*h_path--; // danger zone

	while (*++h_path)
	{
		up = 0; nx = 0; dn = 0; pv = 0;
		logger(4, " # ", ret->name, "->", *h_path);
		pv = ret;
		if (ret->nx)
			up = node_last_dn(ret->nx);
		ret = node_new(ft_strdup(*h_path), 0, up, nx, dn, pv);
		logger_rose(ret);
	}

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
	node *nd = node_goto(data, chain[0]);
	if (!nd)
	{
		logger(3, "Did not find ", chain[0], ".");
		ft_strfree2d(chain);
		return 0;
	}
	logger(2, "Can post as a child of ", nd->name);
	nd->value = ft_x(nd->value, correct_quotes(chain[1]));
	ft_strfree2d(chain);
	return json_render_node(nd->pv, 0, 1);
}

str json_del(json* data, str path)
{
	logger(2, "\\ del ", path);
	str path_no_reserved = no_reserved(path);
	node* ret;
	if (ft_stridentical(path, path_no_reserved))
	{
		node *h = node_goto(data, path);
		free(path_no_reserved);
		if (!h)
		{
			logger(3, "  - Could not go to ", path, ". Die.");
			return 0;
		}
		logger_rose(h);
		ret = h->pv;
		node_del(h);
		logger(1, "/");
		return json_render_node(ret, 0, 0);
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
