/* ******************************************* */
/*                                             */
/*                     :|::::::|:::|:|::|::||: */
/* ft_ltoa.c           :::||:|:|:||::|:|||:::| */
/*                     ||:||:||||::||||||:|::: */
/*     :::|:: <:::|::>                         */
/*                                             */
/* C20200213011328 :::|::                      */
/* U20200213011617 |:||||                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_ltoa(long n)
{
	unsigned int	len;
	char			*w;
	long long		t;
	char			*r;

	t = n < 0 ? (long long)n * -1 : (long long)n;
	len = n < 0 ? 2 : 1;
	while (t /= 10)
		len++;
	r = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!r)
		return (NULL);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = n < 0 ? (long long)n * -10 : (long long)n * 10;
	while (t /= 10)
		*w-- = (t % 10) + '0';
	if (n < 0)
		*w = '-';
	return (r);
}
