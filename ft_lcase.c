/* ******************************************* */
/*                                             */
/*                     ::||||||::|||:::||::|:: */
/* ft_lcase.c          ||:||||:||::::|:::|:||| */
/*                     :|::|:|:||:|:|::::::||| */
/*     :::::| <:::::|>                         */
/*                                             */
/* C20200214131257 :::::|                      */
/* U20200214220306 ::::||                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_lcase(char *str)
{
	char	*dst;
	int		i;

	dst = ft_calloc(ft_strlen((const char *)str) + 1, 1);
	i = 0;
	while (str[i])
	{
		dst[i] = ft_tolower(str[i]);
		i++;
	}
	return (dst);
}
