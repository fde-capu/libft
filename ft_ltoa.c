/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* ft_ltoa.c           :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     ||:::| <||:::|>                         */
/*                                             */
/* C20200218110256 ||:::|                      */
/* U20200218121353 :|::||                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_ltoa(signed long n)
{
	char			*w;
	unsigned long	t;
	char			*r;

	t = ft_abs(n);
	r = ft_ultoa(t);
	if (n >= 0)
		return (r);
	w = ft_calloc(ft_strlen(r) + 2, 1);
	w[0] = '-';
	ft_memmove(&w[1], (void *)r, ft_strlen(r));
	return (w);
}
