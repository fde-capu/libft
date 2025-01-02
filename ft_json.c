/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 21:44:42 by fde-capu         ###   ########.fr       */
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
	node* nd = node_goto(data, path);
	if (nd)
		return json_render_node(nd, 0, 0);

	logger(2, "\\ put ", path);

	str* splitpath = path_split(path);
	str* h_path = splitpath;
	node* ret = data->base_node;
	nd = data->base_node->nx;

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

	node *up = 0;
	node *nx = 0;
	node *dn = 0;
	node *pv = 0;

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
	if (!ft_strstr("=", path))
		return json_put(data, path);

	str* chain = ft_split_set(path, "=,");
	node *nd = node_goto_force(data, chain[0]);
	logger(2, "\\ post ", path);
	nd->value = ft_x(nd->value, correct_quotes(chain[1]));
	str raw_path = node_raw_path(data, nd->pv);
	logger(2, "  - raw ", raw_path);
	if (chain[2])
	{
		nd = nd->pv;
		int i = 2;
		while (chain[i])
		{
			logger(4, "  # ", chain[i], " : ", chain[i + 1]);
			str new_el = ft_strcat_variadic(2, raw_path, chain[i]);
			nd = node_goto_force(data, new_el);
			nd->value = ft_x(nd->value, correct_quotes(chain[i + 1]));
			free(new_el);
			i += 2;
		}
	}
	free(raw_path);
	ft_strfree2d(chain);
	logger(1, "/");
	return json_render_node(nd, 0, 1);
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
		logger(3, "  - Will use ", path_no_reserved, " instead.");
		node *h = node_goto(data, path_no_reserved);
		free(path_no_reserved);
		if (!h)
			return 0;
		free(h->value);
		h->value = 0;
		logger(1, "/");
		return json_render_node(h, 0, 0);
	}
}
