/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 21:49:37 by fde-capu         ###   ########.fr       */
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
	node* n = data->base_node->attribute;
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
				if (n->attribute)
				{
					n = n->attribute;
					*p++;
				}
				else
				{
					break ;
				}
			}
			else
				break ;
		}
		else
		{
			n = n->nx;
		}
	}
	if (!ft_stridentical(r->name, *p))
		r = 0;
	ft_strfree2d(splitpath);
	return r;
}

node* node_goto_before_last(json *data, str path)
{
	node* n = data->base_node->attribute;
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
				n = n->attribute;
				*p++;
			}
			else
				break ;
		}
		else
			n = n->nx;
	}
	ft_strfree2d(splitpath);
	return o;
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

node* node_new()
{
	node* out = calloc(sizeof(node), 1);
	return out;
}

str json_put(json* data, str path)
{
	node* n = data->base_node->attribute;
	node* b = data->base_node;
	str* splitpath = path_split(path);
	str* p = splitpath;

	while (n)
	{
		if (ft_stridentical(n->name, *p))
		{
			b = n;
			if (*(p + 1))
			{
				n = n->attribute;
				*p++;
			}
			else
				break ;
		}
		else
			n = n->nx;
	}
	while (*p)
	{
		b->attribute = node_new();
		b = b->attribute;
		b->name = ft_strdup(*p);
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
	nodelist_free(h->attribute);
	h->attribute = 0;
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
