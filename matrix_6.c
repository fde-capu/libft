/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:00:20 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/14 11:30:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_destroy(t_mat *mat)
{
	if (!mat)
		return ;
	lstdbl_destroy(mat->i);
	free(mat);
	return ;
}

t_mat	*matrix_of_minors(t_mat *a)
{
	t_mat	*mom;
	t_mat	*minor;
	int		i;
	int		j;

	mom = matrix_new();
	i = 1;
	while (i <= a->m)
	{
		j = 1;
		while (j <= a->n)
		{
			minor = matrix_minor(a, i, j);
			mom->i = lstdbl_addlast(mom->i, matrix_determinant(minor));
			matrix_destroy(minor);
			j++;
		}
		i++;
	}
	mom->m = a->m;
	mom->n = a->n;
	return (mom);
}
