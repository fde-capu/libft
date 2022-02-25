/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/25 20:08:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	json* data = json_new();
	str out_put = json_put(data, "/test/haha");
	if (out_put)
		printf("out_put: %s\n", out_put);
	str out_get = json_get(data, "/test/haha");
	if (out_get)
		printf("out_get: %s\n", out_get);
	json_clean(data);
	free(out_get);
	free(out_put);
	return 0;
}
