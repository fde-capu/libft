/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_iho_to_base.c    ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     :|:|:| <:|:|:|>                         */
/*                                             */
/* C20200214102551 :|:|:|                      */
/* U20200214135527 :||||:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_iho_to_base(char *nbr, int base_to)
{
	int	base_from;

	base_from = ft_isoct(nbr) ? 8 : 10;
	base_from = ft_ishex(nbr) ? 16 : base_from;
	return (ft_convert_base(nbr, base_from, base_to));
}
