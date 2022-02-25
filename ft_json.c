/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 17:15:24 by fde-capu         ###   ########.fr       */
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
	node* r = 0;

	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical(n->name, *p))
		{
			r = n;
			if (*p + 1)
			{
				n = n->attribute;
				*p++;
			}
			else
				break ;
		}
		n = n->nx;
	}
	ft_strfree2d(splitpath);
	return r;
}

str	json_get(json* data, str path)
{
	node* h = node_goto(data, path);
	str out;

	if (!h)
	{
		out = ft_str();
	}
	else
	{
		str out = ft_strdup(h->name);
	}
	return out;
}

node* new_node()
{
	node* out = calloc(sizeof(node), 1);
	return out;
}

json* json_new()
{
	json* new_json = calloc(sizeof(json), 1);
	new_json->base_node = new_node();
	new_json->base_node->name = ft_str("baseNode");
	return new_json;
}

void nodelist_free(node* n)
{
	if (!n)
		return ;
	if (n->nx)
		nodelist_free(n->nx);
	nodelist_free(n->attribute);
	free(n->name);
	free(n->value);
	free(n);
	return ;
}

void json_clean(json *this)
{
	nodelist_free(this->base_node);
	free(this);
	return ;
}
