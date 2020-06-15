/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:23:53 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/12 00:05:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

int		on_press(int kc, int (fun)())
{
	key(kc)->st = KEY_ON;
	DEBINT2("pressed", kc, key(kc)->st);
	fun();
	return (1);
}

int		on_release(int kc, int (fun)())
{
	key(kc)->st = KEY_OFF;
	DEBINT2("release", kc, key(kc)->st);
	fun();
	return (1);
}
