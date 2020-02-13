/* ******************************************* */
/*                                             */
/*                     :||:|:|:||:||::||:::||| */
/* ft_ltoh.c           :|::||||:|||::|:|:::|:| */
/*                     |||||::::|::|::::::||:| */
/*     :::::: <::::::>                         */
/*                                             */
/* C20200205181938 ::::::                      */
/* U20200213022933 |:::|:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_ltoh(unsigned long value)
{
	int				i;
	unsigned long	c;
	int				t;
	char			*n;
	char			*r;

	r = ft_calloc(1 + ft_countdigits((long long) value), 1);
	if (!r)
		return (NULL);
	n = r;
	i = 0;
	c = value;
	while (c != 0)
	{
		t = c % 16;
		t += t < 10 ? '0' : 'a';
		n[i] = t;
		i++;
		c = c / 16;
	}
	n[i] = 0;
	return (&n[0]);
}
