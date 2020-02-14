/* ******************************************* */
/*                                             */
/*                     :|:::|::::|:|::|::||::: */
/* ft_btod.c           ||:|:|:||::|:|||::::::| */
/*                     ||:||:||||::||||||:|::: */
/*     |::|:: <|::|::>                         */
/*                                             */
/* C20200214180021 |::|::                      */
/* U20200214193222 ::::|:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

double	ft_btod_single(char n)
{
	int	r;

	r = *(int *)ft_lcase(&n);
	r -= n >= '0' && n <= '9' ? '0' : 0;
	r -= n >= 'a' && n <= 'z' ? 'a' + 10 : 0;
	return (r);
}

double	ft_btod(char *nbr, int b_from)
{
	double	e;
	char	*p;
	double	v;

	e = 1;
	v = 0;
	p = nbr + ft_strlen(nbr) - 1;
	while (p >= nbr)
	{
		v += (ft_btod_single(*p) * e); 
		e *= b_from;
		p--;
	}
	return (e);
}
