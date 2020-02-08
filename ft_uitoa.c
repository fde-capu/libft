/* ******************************************* */
/*                                             */
/*                     :|||::|||:||||:::|||||| */
/* ft_uitoa.c          :|::||::|::|:||::::||:| */
/*                     |:|:|:::|::::::|:|:|||: */
/*     |:|||: <|:|||:>                         */
/*                                             */
/* C20200208192036 |:|||:                      */
/* U20200208192511 |:|||:                      */
/*                                             */
/* ******************************************* */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*w;
	long			t;
	char			*r;

	t = (long)n;
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
	t = (long)n * 10;
	while (t /= 10)
		*w-- = (t % 10) + '0';
	return (r);
}

