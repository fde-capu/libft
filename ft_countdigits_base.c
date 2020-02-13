/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_countdigits_bas  ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200213172548 :::|:|                      */
/* U20200213172644 :|:||:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

unsigned int	ft_countdigits_base(long long number, unsigned int base)
{
	unsigned int	c;
	
	c = 1;
	while (number > base)
	{
		c++;
		number /= base;
	}
	return (c);
}
