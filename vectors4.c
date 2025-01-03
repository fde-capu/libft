/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:15:00 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/22 14:48:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_normalize(t_vec *mv)
{
	t_dbl	*h;
	double	mag;

	mag = vector_magnitude(mv);
	if (!mag)
		return ;
	h = mv->i;
	while (h)
	{
		h->d /= mag;
		h = h->nx;
	}
	return ;
}

int		is_normalized(t_vec *vec)
{
	double	mag;

	mag = vector_magnitude(vec);
	if (mag > 0.9 && mag < 1.1)
		return (1);
	return (0);
}

double	vector_dot_product(t_vec *v1, t_vec *v2)
{
	double	dp;
	t_dbl	*h1;
	t_dbl	*h2;

	h1 = v1->i;
	h2 = v2->i;
	dp = 0;
	while (h1 && h2)
	{
		dp += (h1->d * h2->d);
		h1 = h1->nx;
		h2 = h2->nx;
	}
	if (h1 || h2)
		ft_die(DOTPRODERR, ERRDOTPROD);
	return (dp);
}

double	vector_modulus(t_vec *v)
{
	return (vector_dot_product(v, v));
}

double	vector_scalar_product(t_vec *v1, t_vec *v2)
{
	return (vector_dot_product(v1, v2));
}
