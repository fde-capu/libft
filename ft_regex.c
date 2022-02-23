/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:46:36 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/23 15:42:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*test_options(const char *sh, char *rh)
{
	int		i;
	char	**opt;
	char	*str;

	opt = ft_insplit(rh, '|');
	i = 0;
	while ((opt[1]) && (opt[i]))
	{
		str = ft_check(sh, opt[i]);
		if (str)
		{
			ft_strfree2d(opt);
			return (str);
		}
		if (!opt[++i])
		{
			ft_strfree2d(opt);
			return (0);
		}
	}
	ft_strfree2d(opt);
	return (0);
}

static char	*free_and_ret(char *blk, char *ret)
{
	free(blk);
	return (ret);
}

static char	*test_function(int fun, int mm[2], char *sh, char *blk)
{
	if ((fun == FUN_SET) || (!rgx_fun_in(fun)))
	{
		while (mm[0]-- > 0)
		{
			if ((*sh) && (!rgx_chk_function(fun, sh++, blk)))
			{
				rgx_maybe_free(blk, fun);
				return (0);
			}
		}
		while ((--mm[1]) && (rgx_chk_function(fun, sh, blk)))
			sh++;
	}
	if (fun == FUN_PAR)
	{
		while (mm[0]-- > 0)
		{
			sh = rgx_chk_function(fun, sh, blk);
			return (free_and_ret(blk, 0));
		}
		while (--mm[1])
			sh = rgx_chk_function(fun, sh, blk);
	}
	return (sh);
}

/*
** ft_check
** returns pointer to first unmatched char (or nothing)
*/

char	*ft_check(const char *sh, char *rh)
{
	int		mm[2];
	char	*blk;
	int		fun;

//	ft_print(sh); ft_print(" || "); ft_print(rh); ft_print("\n");
	if (rh && *rh == '$' && (*sh))
	{
		//ft_print("$\n");
		return (0);
	}
	if ((!rh) || (!*rh))
	{
		//ft_print("rh\n");
		return ((char *)sh);
	}
	if (ft_insp_count(rh, '|') != 1)
	{
		//ft_print("|\n");
		return (test_options(sh, rh));
	}
	fun = rgx_function_n(rh);
	rh += ft_ternary_i(ft_strbegins(rh, "\\"), 1, 0);
	blk = ft_ternary_c(rgx_fun_in(fun), ft_inside(rh), rh);
	rgx_set_rep(&mm[0], ft_inskip(rh));
	sh = test_function(fun, mm, (char *)sh, blk);
	if (!sh)
	{
		//ft_print("sh\n");
		return (0);
	}
	if (rgx_fun_in(fun))
		free(blk);
	rh = rgx_sk_mod(ft_inskip(rh));
	return (ft_check(sh, rh));
}

bool	ft_check_full(const char *sh, char *rh)
{
	int		mm[2];
	char	*blk;
	int		fun;

//	ft_print(ft_itoa(ft_atoi(sh))); ft_print(") ");
//	ft_print(sh); ft_print("---"); ft_print(rh); ft_print("\n");
	if (rh && *rh == '$' && (*sh))
	{
//		ft_print("$\n");
		return (0);
	}
	if (rh && *rh && !*sh)
	{
//		ft_print("not full");
		return 0;
	}
	if ((!rh) || (!*rh) && (!*sh))
	{
//		ft_print("complete\n");
		return ((char *)sh);
	}
	if (ft_insp_count(rh, '|') != 1)
	{
//		ft_print("|\n");
		return (test_options(sh, rh));
	}
	fun = rgx_function_n(rh);
	rh += ft_ternary_i(ft_strbegins(rh, "\\"), 1, 0);
	blk = ft_ternary_c(rgx_fun_in(fun), ft_inside(rh), rh);
	rgx_set_rep(&mm[0], ft_inskip(rh));
	sh = test_function(fun, mm, (char *)sh, blk);
	if (!sh)
	{
//		ft_print("sh\n");
		return (0);
	}
	if (rgx_fun_in(fun))
		free(blk);
	rh = rgx_sk_mod(ft_inskip(rh));
	return (ft_check_full(sh, rh));
}
