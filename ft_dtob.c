/* ******************************************* */
/*                                             */
/*                     :|:::|::::|:|::|::||::: */
/* ft_dtob.h           ||:|:|:||::|:|||::::::| */
/*                     ||:||:||||::||||||:|::: */
/*     ||:||: <||:||:>                         */
/*                                             */
/* C20200214182613 ||:||:                      */
/* U20200216224306 ::|||:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

static char	ft_dtob_single(int c)
{
	int	r;

	c = ft_abs(c);
	r = 0;
	r = 0 <= c && c <= 9 ? c + '0' : r;
	r = c > 9 ? c + ('a' - 10) : r; 
	return (r);
}

char		*ft_dtob(long long numb, int b_to)
{
	int			fsp;
	char		*dst;
	char		*p;
	int			c;
	long long	n;

	n = ft_abs(numb);
	fsp = b_to == 2 ? 4 : 1;
	fsp = b_to == 3 || b_to == 4 ? 3 : fsp;
	fsp = b_to >= 5 && b_to <= 9 ? 2 : fsp;
	dst = ft_calloc((ft_countdigits(n) * fsp) + 2, 1);
	p = dst;
	c = 0;
	while (n)
	{
		c = (int)(n % b_to);
		*p = ft_dtob_single(c);
		n = (long long)(n / b_to);
		p++;
	}
	if (numb < 0)
		*p = '-';
	p = ft_strrev(dst);
	free(dst);
	return (p);
}