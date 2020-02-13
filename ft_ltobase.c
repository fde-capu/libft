/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_ltobase.c        ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200213173955 :::|:|                      */
/* U20200213181157 ::|:|:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_ltobase(long long value, unsigned int base)
{
	int					i;
	unsigned long long	c;
	unsigned long long 	t;
	char				*n;
	char				*r;

	i = ft_countdigits_base(value, base);
	r = ft_calloc(i + 1, 1);
	if (!r)
		return (NULL);
	n = r;
	i -= 1;
	c = ft_abs(value);
	while (c != 0)
	{
		t = c % base;
		t += t < 10 ? '0' : 'a' - 10;
		n[i] = t;
		i--;
		c = c / base;
	}
	n[i] = value < 0 ? '-' : n[i];
	return (&n[0]);
}
