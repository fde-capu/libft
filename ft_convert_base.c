/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_convert_base.c   ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     |:||:: <|:||::>                         */
/*                                             */
/* C20200214092047 |:||::                      */
/* U20200217183426 ::::|:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_convert_base(const void *bdata, ...)
{
	va_list	bd;
	char	*nbr;
	int		b_fr;
	int		b_to;
	char	*dec;

	va_start(bd, bdata);
	nbr = va_arg(bd, void *);
	b_fr = va_arg(bd, int);
	b_to = va_arg(bd, int);
	va_end(bd);
	if ((b_fr == 10) && (b_to == 10))
		return (nbr);
	if (b_fr == 10)
		return (ft_dtob(ft_atoi(nbr), b_to));
	if (b_to == 10)
		return (ft_itoa(ft_btod(nbr, b_to)));
	dec = ft_itoa(ft_btod(nbr, b_fr));
	dec = ft_dtob(ft_atoi(dec), b_to);
	return(dec);
}
