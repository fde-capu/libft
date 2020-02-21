/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_countdigits_ibas  ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200213172548 :::|:|                      */
/* U20200214125710 |||||:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

unsigned int	ft_countdigits_ibase(long long number, unsigned int base)
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
