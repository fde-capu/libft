/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/26 18:35:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

str api_request(str method, str command, json* base)
{
	printf("(%s %s) ", method, command);
	if (ft_stridentical_insensitive(method, "del"))
		return json_del(base, command);
	if (ft_strstr("value", command))
		return ft_str("409 read the docs");
	if (ft_stridentical_insensitive(method, "get"))
		return json_get(base, command);
	if (ft_stridentical_insensitive(method, "put"))
		return json_put(base, command);
	if (ft_stridentical_insensitive(method, "post"))
		return json_post(base, command);
	return ft_str("404 ki ki ki");
}

int main()
{
	json* data = json_new();
	str out;

	json_render(data);

	out = api_request("put", "/universe/galaxy", data);
	printf("> %s\n", out);
	json_render(data);
	
	out = ft_x(out, api_request("put", "/universe/galaxy", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("put", "/universe/gas_cloud", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("get", "/universe/galaxy", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("del", "/universe/galaxy", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("del", "/universe/bas_cloud/", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("del", "/universe/gas_cloud/", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/type='SA(s)b'", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/type/sub=(s)b", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/type/value='X'", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("del", "/universe/galaxy/Andromeda/type/value", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("del", "/universe/galaxy/Andromeda/type/sub", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/type=SA(s)b", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/type=SA(s)b", data));
	printf("> %s\n", out);
	json_render(data);

	out = ft_x(out, api_request("del", "/universe/galaxy/Andromeda/type/value", data));
	printf("> %s\n", out);
	json_render(data);


//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/color_bv='0.92',contrast_index=0.98,surface_brightness='13;35'", data));
//	printf("> %s\n", out);
//	json_render(data);
//
//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/surface_brightness/unit='mag/arcmin2'", data));
//	printf("> %s\n", out);
//	json_render(data);
//
//	out = ft_x(out, api_request("put", "/universe/galaxy/star/", data));
//	printf("> %s\n", out);
//	json_render(data);
//
//	out = ft_x(out, api_request("post", "/universe/galaxy/star='Zubenelgenubi 1'", data));
//	printf("> %s\n", out);
//	json_render(data);
//
//	out = ft_x(out, api_request("post", "/universe/galaxy/star/Zubenelgenubi 2", data));
//	printf("> %s\n", out);
//	json_render(data);
//
//	out = ft_x(out, api_request("post", "/universe/galaxy/star/type='binary'", data));
//	printf("> %s\n", out);
//	json_render(data);
//
//	out = ft_x(out, api_request("post", "/universe/galaxy/star/type='binary'", data));
//	printf("> %s\n", out);
//	json_render(data);

	free(out);
	json_clear(data);

	return 0;
}
