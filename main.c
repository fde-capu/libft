/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/26 01:37:26 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	json* data = json_new();

	str out;
	str com;

	json_render(data);

	com = ft_str("/universe/galaxy");
	out = json_put(data, com);
	if (out) { printf("put %s: %s\n", com, out); }
	json_render(data);

	com = ft_strx("/universe/gas_cloud", com);
	out = ft_x(out, json_put(data, com));
	if (out) { printf("put %s: %s\n", com, out); }
	json_render(data);

	com = ft_strx("/universe/galaxy", com);
	out = ft_x(out, json_get(data, com));
	if (out) { printf("get %s: %s\n", com, out); }
	json_render(data);

	com = ft_strx("/universe/galaxy", com);
	out = ft_x(out, json_del(data, com));
	if (out) { printf("del %s: %s\n", com, out); }
	json_render(data);

	free(out);
	free(com);

//	out = json_get(data, "/universe/galaxy");
//	if (out)
//		printf("out: %s\n", out);
//
//	out = json_put(data, "a");
//	if (out)
//		printf("out: %s\n", out);
//
//	free(out);
//	free(out);
////	free(out);

	json_clear(data);
	return 0;
}
