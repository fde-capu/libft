/* ******************************************* */
/*                                             */
/*                     :|:|:|::|:||:|:|||:|::: */
/* ft_whichar.c        |::||:||::|::::||:::||| */
/*                     ::||||:||||||::::::|:|: */
/*     |::|:: <|::|::>                         */
/*                                             */
/* C20200207175626 |::|::                      */
/* U20200214180902 |||:|:                      */
/*                                             */
/* ******************************************* */
/*
** Gets negative from `x` to point to char
** counting from the end of `char *`.
*/

#include "libft.h"

char	ft_whichar(const char *s, int x)
{
	char	*z;
	char	r;

	z = (char *)s;
	while (x < 0)
	{
		x += ft_strlen(z);
	}
	r = *(z + x);
	return (r);
}
