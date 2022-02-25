/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:32:42 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 14:07:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

str	get(json* data, str path)
{
	printf("> GET: ");
	str out = data->base_node->name;
	return out;
}

node* new_node()
{
	return calloc(sizeof(node), 1);
}

json new_json()
{
	json new_json;
	new_json.base_node = new_node();
	new_json.base_node->name = ft_str("baseNode");
	return new_json;
}

node* create_node(node *parent)
{
	parent->nx = new_node();
	return parent->nx;
}
