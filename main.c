/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/26 00:45:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	json* data = json_new();

	str out_put;
	str out_get;
	str out_del;
	str com;

	json_render(data);

	com = ft_str("/universe/galaxy");
	out_put = json_put(data, com);
	if (out_put) { printf("put %s: %s\n", com, out_put); }
	
	json_render(data);

	com = ft_strx("/universe/gas_cloud", com);
	out_put = ft_x(out_put, json_put(data, com));
	if (out_put) { printf("put %s: %s\n", com, out_put); }
	
	json_render(data);

	out_get = json_get(data, "/universe/galaxy");
	if (out_get)
		printf("out_get: %s\n", out_get);

	out_del = json_del(data, "/universe/galaxy");
	if (out_del)
		printf("out_del: %s\n", out_del);

	free(out_get);
	free(out_put);
	free(out_del);
	free(com);

//	out_get = json_get(data, "/universe/galaxy");
//	if (out_get)
//		printf("out_get: %s\n", out_get);
//
//	out_put = json_put(data, "a");
//	if (out_put)
//		printf("out_put: %s\n", out_put);
//
//	free(out_get);
//	free(out_put);
////	free(out_del);

	json_clean(data);
	return 0;
}
