/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 19:33:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void logger(int argc, ...);

str api_request(str method, str command, json* base)
{
	logger(4, "< ", method, " ", command);
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

	logger(1, "1)");
	out = api_request("put", "universe", data);
	logger(2, "> ", out);
	json_render(data);
	
	logger(1, "2)");
	out = ft_x(out, api_request("put", "another_universe", data));
	logger(2, "> ", out);
	json_render(data);
	
	logger(1, "3)");
	out = ft_x(out, api_request("put", "universe/galaxy", data));
	logger(2, "> ", out);
	json_render(data);
	
	logger(1, "4)");
	out = ft_x(out, api_request("put", "another_universe/gas_cloud", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "5)");
	out = ft_x(out, api_request("del", "another_universe/gas_cloud", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "6)");
	out = ft_x(out, api_request("put", "another_universe/gas_cloud", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "7)");
	out = ft_x(out, api_request("del", "another_universe", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "9)");
	out = ft_x(out, api_request("put", "another_universe/gas_cloud", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "9)");
	out = ft_x(out, api_request("del", "universe/galaxy", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "10)");
	out = ft_x(out, api_request("put", "universe/galaxy", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "11)");
	out = ft_x(out, api_request("del", "universe", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "12)");
	out = ft_x(out, api_request("put", "universe/galaxy/milkyway", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "13)");
	out = ft_x(out, api_request("put", "another_universe/galaxy/inverted_milkyway", data));
	logger(2, "> ", out);
	json_render(data);

	logger(1, "14)");
	out = ft_x(out, api_request("put", "yau/galaxy_cluster/unknown", data));
	logger(2, "> ", out);
	json_render(data);

//	logger(1, "15)");
//	out = ft_x(out, api_request("del", "universe", data));
//	logger(2, "> ", out);
//	json_render(data);

//	logger(1, "16)");
//	out = ft_x(out, api_request("get", "/universe", data));
//	logger(2, "> ", out);
//	json_render(data);
//
//	logger(1, "18)");
//	out = ft_x(out, api_request("DEL", "/universe/galaxy", data));
//	logger(2, "> ", out);
//	json_render(data);
//
//	logger(1, "19)");
//	out = ft_x(out, api_request("del", "/universe/gas_cloud", data));
//	logger(2, "> ", out);
//	json_render(data);
//
//	logger(1, "20)");
//	out = ft_x(out, api_request("put", "/universe/galaxy", data));
//	logger(2, "> ", out);
//	json_render(data);

//	logger(1, "21)");
//	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/", data));
//	json_render(data);
//
//	logger(1, "22)");
//	out = ft_x(out, api_request("del", "/universe/bas_cloud/", data));
//	json_render(data);
//
//	logger(1, "23)");
//	out = ft_x(out, api_request("del", "/universe/gas_cloud/", data));
//	json_render(data);
//
//	logger(1, "24)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/type='SA(s)b'", data));
//	json_render(data);

//	logger(1, "25)");
//	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/type/sub=(s)b", data));
//	json_render(data);
//
//	logger(1, "26)");
//	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/type/value='X'", data));
//	json_render(data);
//
//	logger(1, "27)");
//	out = ft_x(out, api_request("del", "/universe/galaxy/Andromeda/type/value", data));
//	json_render(data);
//
//	logger(1, "28)");
//	out = ft_x(out, api_request("del", "/universe/galaxy/Andromeda/type/sub", data));
//	json_render(data);
//
//	logger(1, "29)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/type=SA(s)b", data));
//	json_render(data);
//
//	logger(1, "30)");
//	out = ft_x(out, api_request("put", "/universe/galaxy/Andromeda/type=SA(s)b", data));
//	json_render(data);
//
//	logger(1, "31)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/color_bv='0.92'", data));
//	json_render(data);

//	logger(1, "32)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/color_bv='0.92',contrast_index=0.98,surface_brightness=13;35", data));
//	json_render(data);

//	logger(1, "33)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/Andromeda/surface_brightness/unit='mag/arcmin2'", data));
//	json_render(data);
//
//	logger(1, "34)");
//	out = ft_x(out, api_request("put", "/universe/galaxy/star/", data));
//	json_render(data);
//
//	logger(1, "35)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/star='Zubenelgenubi 1'", data));
//	json_render(data);
//
//	logger(1, "36)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/star/Zubenelgenubi 2", data));
//	json_render(data);
//
//	logger(1, "37)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/star/type='binary'", data));
//	json_render(data);
//
//	logger(1, "38)");
//	out = ft_x(out, api_request("post", "/universe/galaxy/star/type='binary'", data));
//	json_render(data);

// put repeated
//	out = ft_x(out, api_request("put", "/universe/galaxy", data));
//	logger(2, "> ", out);
//	json_render(data);
//
	free(out);
	json_clear(data);

	return 0;
}
