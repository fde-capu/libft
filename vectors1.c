/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 08:42:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i2d	ft_i2d(int x, int y)
{
	t_i2d	o;

	o.x = x;
	o.y = y;
	return (o);
}

t_d3d	ft_d3d(double x, double y, double z)
{
	t_d3d	o;

	o.x = x;
	o.y = y;
	o.z = z;
	return (o);
}

t_vec	*ft_vec(double f_arg, ...)
{
	va_list	ap;
	t_vec	*vec;
	int		n;
	double	d;

	va_start(ap, f_arg);
	vec = ft_calloc(sizeof(t_mat), 1);
	vec->i = ft_lstdbl_new(va_arg(ap, double));
	n = 1;
	while ((d = va_arg(ap, double)))
	{
		n++;
		ft_lstdbl_addlast(vec->i, d);
	}
	va_end(ap);
	vec->n = n;
	vec->m = 1;
	return (vec);
}

t_mat	*ft_mat(int m, ...)
{
	va_list	ap;
	t_mat	*mat;
	double	d;
	int		argc;

	mat = ft_calloc(sizeof(t_mat), 1);
	va_start(ap, m);
	mat->i = ft_lstdbl_new(va_arg(ap, double));
	argc = 0;
	while ((d = va_arg(ap, double)))
	{
		argc++;
		ft_lstdbl_addlast(mat->i, d);
	}
	va_end(ap);
	mat->m = m;
	mat->n = ft_ceil((double)argc / (double)m);
	return (mat);
}
