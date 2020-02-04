/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:22:20 by fde-capu          #+#    #+#             */
/* U20200203215234 :|::||                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int x;
	
	x = ft_strlen(s1) > ft_strlen(s2) ? \
		(int)ft_strlen(s1) : (int)ft_strlen(s2);
	return (ft_strncmp(s1, s2, x));
}
