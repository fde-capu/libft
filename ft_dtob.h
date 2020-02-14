/* ******************************************* */
/*                                             */
/*                     :|:::|::::|:|::|::||::: */
/* ft_dtob.h           ||:|:|:||::|:|||::::::| */
/*                     ||:||:||||::||||||:|::: */
/*     ||:||: <||:||:>                         */
/*                                             */
/* C20200214182613 ||:||:                      */
/* U20200214192942 |||:::                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	ft_dtob_single(int c)
{
	char	r;

	c = ft_abs(c);
	r = 0;
	r = 0 <= c && c <= 9 ? r + '0' : r;
	r = c > 9 ? r + 'a' - 10 : r; 
	return (r);
}

char	*ft_dtob(double n, int b_to)
{
	int		fsp;
	char	*dst;
	char	*p;
	int		c;

	fsp = b_to == 2 ? 4 : 1;
	fsp = b_to == 3 || b_to == 4 ? 3 : fsp;
	fsp = b_to >= 5 && b_to <= 9 ? 2;
	dst = ft_calloc(ft_countdigits(n) * fsp + 2, 1);
	p = dst;
	while (n)
	{
		c = n % b_to;
		*p = ft_dtob_single(c);
		p++;
		n = (long long)(n / b_to);
	}
	p = ft_strrev(p);
	free(dst)
	return (p);
}
