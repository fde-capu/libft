/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:35:53 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 13:36:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

str json_render(json* data)
{
	str out = json_render_node(data->base_node->nx, 1, 1);
	logger(3, "---\n", out, "\n---");
	if (out)
		free(out);
	return 0;
}

void logger(int argc, ...)
{
	va_list h;
	va_start(h, argc);
	str out = ft_str(NEW_LINE);
	while (argc--)
		out = ft_x(out, ft_strcat(out, va_arg(h, char *)));
	va_end(h);

	write(LOG_FD, out, ft_strlen(out));

	free(out);
}

str* path_split(str path)
{
	return ft_split(path, '/');
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

str correct_quotes(str in)
{
	int len = ft_strlen(in);

	if
	(
		in[0] == in[len - 1] \
		&& ft_chrinset(in[0], "\"'")
	)
	{
		str out = ft_substr(in, 1, len - 2);
		out = ft_x(out, ft_strcat_variadic(3, "'", out, "'"));
		return out;
	}
	return ft_strcat_variadic(3, "'", in, "'");
}

str no_reserved(str path)
{
	char * h = ft_strnstr(path, "value", ft_strlen(path));
	return h > path ? ft_substr(path, 0, h - path) : ft_strdup(path);
}

void logger_rose(node *nd)
{
	str out = ft_str("\t@ ");
	if (nd->up)
	{
		out = ft_strcatxx(out, ft_str(nd->up->name));
		if (nd->up->dn != nd)
			out = ft_strcatxx(out, ft_strcat_variadic(3, "-nx->(", nd->up->dn ? nd->up->dn->name : "0", ")"));
	}
	out = ft_strcatxl(out, " \n");

	out = ft_strcatxl(out, "\tV ");
	if (nd->nx)
	{
		out = ft_strcatxx(out, ft_str(nd->nx->name));
		if (nd->nx->pv != nd)
			out = ft_strcatxx(out, ft_strcat_variadic(3, "-nx->(", nd->nx->pv ? nd->nx->pv->name : "0", ")"));
	}
	out = ft_strcatxl(out, " \n");

	out = ft_strcatxl(out, "\t/ ");
	if (nd->dn)
	{
		out = ft_strcatxx(out, ft_str(nd->dn->name));
		if (nd->dn->up != nd)
			out = ft_strcatxx(out, ft_strcat_variadic(3, "-nx->(", nd->dn->up ? nd->dn->up->name : "0", ")"));
	}
	out = ft_strcatxl(out, " \n");

	out = ft_strcatxl(out, "\t| ");
	if (nd->pv)
	{
		out = ft_strcatxx(out, ft_str(nd->pv->name));
		if (nd->pv->nx != nd)
			out = ft_strcatxx(out, ft_strcat_variadic(3, "-nx->(", nd->pv->nx ? nd->pv->nx->name : "0", ")"));
	}

	logger(1, out);
	free(out);
	return ;
}
