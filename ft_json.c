/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 14:49:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

str* path_split(str path)
{
	str f = ft_strdup(path);
	str to_free = f;
	for (f; *f; f++)
	{
		printf("-%s-", f);
	}
	free(to_free);
}

node* node_goto(json* data, str path)
{
	node* h = data->base_node->nx;
	str* splitpath = path_split(path);
	(void)splitpath;
	return h;
}

str	json_get(json* data, str path)
{
	node* h = node_goto(data, path);
	str out = data->base_node->name;
	return out;
}

node* new_node()
{
	node* out = calloc(sizeof(node), 1);
	return out;
}

json json_new()
{
	json new_json;
	new_json.base_node = new_node();
	new_json.base_node->name = ft_str("baseNode");
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
	return ;
}
