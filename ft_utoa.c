/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* ultoa.c             :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     |||::: <|||:::>                         */
/*                                             */
/* C20200218115143 |||:::                      */
/* U20200218122840 |:|:::                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_ultoa(unsigned long n)
{
	unsigned int		len;
	char				*w;
	unsigned long		t;
	char				*r;

	t = n;
	len = 1;
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
	t = n;
	while (t)
	{
		*w-- = (t % 10) + '0';
		t /= 10;
	}
	return (r);
}
