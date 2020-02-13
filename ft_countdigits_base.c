/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_countdigits_bas  ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200213172548 :::|:|                      */
/* U20200213181139 :|:|::                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

unsigned int	ft_countdigits_base(long long number, unsigned int base)
{
	long long	c;
	
	c = number >= 0 ? 1 : 2;
	number = ft_abs(number);
	while (number > base)
	{
		c++;
		number /= base;
	}
	return (c);
}
