/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:10:10 by fde-capu          #+#    #+#             */
/* U20200126195140 :|:|:|                      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

void	title(char *t)
{
	printf("\n%s\n", t);
	while (*t++)
		printf("=");
	printf("\n");
	return ;
}

char	*string(char *txt)
{
	char	*m;
	char	*p;
	char	*r;
	p = txt;
	m = malloc(20);
	r = m;
	while (*p)
	{
		*r = *p;
		r++;
		p++;
	}
	*r = 0;
	return (m);
}


int		test(char *ft)
{
	char	tx[] = "\
	 PART 1 \
		fxt_memset\
		fxt_bzero\
		fxt_memcpy\
		fxt_memccpy\
		fxt_memmove\
		fxt_memchr\
		fxt_memcmp		\
		fxt_strlen\
		fxt_strlcpy\
		fxt_strlcat	\
		fxt_strchr\
		fxt_strrchr\
		fxt_strnstr\
		fxt_strncmp	\
		fxt_atoi		\
		fxt_isalpha	\
		fxt_isdigit	\
		fxt_isalnum	\
		fxt_isascii\
		fxt_isprint	\
		fxt_toupper	\
		fxt_tolower	\
	 PART 1 using malloc \
		fxt_calloc		\
		fxt_strdup		\
	 PART 2 \
		fxt_substr		\
		fxt_strjoin	\
		fxt_strtrim	\
		ft_split		\
		fxt_itoa		\
		fxt_strmapi	\
		fxt_putchar_fd	\
		fxt_putstr_fd	\
		fxt_putendl_fd	\
		fxt_putnbr_fd	\
					";
//	return ((int) ft_strstr(tx, ft));
	return (0);
}

int		main()
{
	printf("\n");
	printf("===== 42cursus_libft ==========================\n");
	printf("===============================================\n");
	printf("================================ fde-capu =====\n");

	if (test("ft_memset")){
	title("ft_memset");
	void *a;
	a = malloc(10);
//	memset(a, 88, 6);
//	printf("SYS:%s\n", a);
	void *bb;
	bb = malloc(10);
	ft_memset(bb, 88, 6);
//	printf("USR:%s\n", bb);
	}

	if (test("ft_bzero")){
	title("ft_bzero");
	void *bz0;
	bz0 = malloc(10);
	bzero(bz0, 6);
//	printf("SYS:-->%s<-- (empty expected)\n", bz0);
	void *bz1;
	bz1 = malloc(10);
	ft_bzero(bz1, 6);
//	printf("USR:-->%s<-- (empty expected)\n", bz1);
	}

	if (test("ft_memmove")){
	title("ft_memmove");
	void *mm0;
	mm0 = malloc(10);
	char mstr0[] = "123456";
	const void *mms0 = mstr0;
	memmove(mm0, mms0, 6);
//	printf("SYS:%s\n", mm0);
	void *mm1;
	mm1 = malloc(10);
	char mstr1[] = "123456";
	const void *mms1 = mstr1;
	ft_memmove(mm1, mms1, 6);
//	printf("USR:%s\n", mm1);
	void *mm2;
	mm2 = malloc(10);
	char mstr2[] = "bolha";
	void *mms2 = mstr2;
	ft_memmove(mms2 + sizeof(char), mms2, 6);
//	printf("S:>bbolha<\nU:>%s<\n", mms2);
	}

	if (test("ft_strlen")){
	title("ft_strlen");
	const char *sl0;
	sl0 = malloc(20);
	//strlcpy((char *)sl0, "1234567890", 17);
	printf("S:%lu\n", strlen(sl0));
	const char *sl1;
//	sl1 = malloc(20);
//	strlcpy((char *)sl1, "1234567890", 17);
	printf("U:%lu\n", strlen(sl1));
	}

	if (test("ft_strlcpy")){
	title("ft_strlcpy");
	char *sls0 = malloc(20);
//	int slc0 = strlcpy(sls0, "abcdefg", 7);
//	printf("S:[%d]-->%s<--\n", slc0, sls0);
	char *sls1 = malloc(20);
	int slc1 = ft_strlcpy(sls1, "abcdefg", 7);
	printf("U:[%d]-->%s<--\n", slc1, sls1);
//	slc0 = strlcpy(sls0, "abcdefg", 3);
//	printf("S:[%d]-->%s<--\n", slc0, sls0);
	slc1 = ft_strlcpy(sls1, "abcdefg", 3);
	printf("U:[%d]-->%s<--\n", slc1, sls1);
//	slc0 = strlcpy(sls0, "abcdefg", 28);
//	printf("S:[%d]-->%s<--\n", slc0, sls0);
	slc1 = ft_strlcpy(sls1, "abcdefg", 28);
	printf("U:[%d]-->%s<--\n", slc1, sls1);
	}

	if (test("ft_memchr")){
		title("ft_memchr");
		const void *mc0;
		char	*mcx0;
		mcx0 = malloc(20);
		ft_strlcpy(mcx0, "123456X78909", 20);	
//		printf("S1:%s\n",memchr(mcx0, 88, 20));
		//printf("U1:%s\n",ft_memchr(mcx0, 88, 20));
//		printf("S2:%s\n",memchr(mcx0, 88, 3));
//		printf("U2:%s\n",ft_memchr(mcx0, 88, 3));
//		printf("S3:%s\n",memchr("bonjour", 'b', 4));
//		printf("U3:%s\n",ft_memchr("bonjour", 'b', 4));
	}

	if (test("ft_memcpy")){
	title("ft_memcpy");
	void *mmc0 = string("123456");
	const void *mmsc0 = string("789012");
	memcpy(mmc0, mmsc0, 6);
//	printf("SYS:%s\n", mmc0);
	void *mmc1 = string("123456");
	const void *mmsc1 = string("789012");
	ft_memcpy(mmc1, mmsc1, 6);
//	printf("USR:%s\n", mmc1);
	void *mmc2 = string("123456");
	const void *mmsc2 = mmc2 + 1;
	memcpy(mmc2, mmsc2, 6);
//	printf("SYS:%s\n", mmc2);
	void *mmc3 = string("123456");
	const void *mmsc3 = mmc3 + 1;
	ft_memcpy(mmc3, mmsc3, 6);
//	printf("USR:%s\n", mmc3);
	}

	if (test("ft_memccpy")){
	title("ft_memccpy");
	void *mmcc0 = string("1234567890");
	const void *mmscc0 = string("789X012");
	memccpy(mmcc0, mmscc0, 88, 6);
//	printf("SYS:%s\n", mmcc0);
	void *mmcc1 = string("1234567890");
	const void *mmscc1 = string("789X012");
	ft_memccpy(mmcc1, mmscc1, 88, 6);
//	printf("USR:%s\n", mmcc1);
	}

	if (test("ft_strnstr")){
		title("ft_strnstr");
		const char *snsh0 = string("ABCDEFGabcHIJKL");
		const char *snsn0 = string("abc");
		const char *snse0 = string("");
		const char *snsx0 = string("XXX");
//		printf("S1:%s\n", strnstr(snsh0, snse0, 6));
		printf("U1:%s\n", ft_strnstr(snsh0, snse0, 6));
//		printf("S2:%s\n", strnstr(snsh0, snsx0, 60));
		printf("U2:%s\n", ft_strnstr(snsh0, snsx0, 60));
//		printf("S3:%s\n", strnstr(snsh0, snsn0, 20));
		printf("U3:%s\n", ft_strnstr(snsh0, snsn0, 20));
//		printf("S4:%s\n", strnstr(snsh0, snsn0, 2));
		printf("U4:%s\n", ft_strnstr(snsh0, snsn0, 2));
//		printf("S5:%s\n", strnstr("lorem ipsum dolor sit amet", "lorem", 15));
		printf("U5:%s\n", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15));
//		printf("S6:%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
		printf("U6:%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
//		printf("S5:%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 0));
		printf("U5:%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0));
	}

	if (test("ft_strchr")){
	title("ft_strchr");
	const char *sch0 = string("0000X1111X2222");
	const char *sch1 = string("X0000X1111X2222");
	printf("S1:%s\n", strchr(sch0, 88));
	printf("U1:%s\n", ft_strchr(sch0, 88));
	printf("S2:%s\n", strchr(sch1, 88));
	printf("U2:%s\n", ft_strchr(sch1, 88));
	printf("S3:%s\n", strchr(sch0, 87));
	printf("U3:%s\n", ft_strchr(sch0, 87));
	printf("S4:-->%s<--\n", strchr(sch0, 0));
	printf("U4:-->%s<--\n", ft_strchr(sch0, 0));
	}

	if (test("ft_strrchr")){
		title("ft_strrchr");
		const char *schr0 = string("0000X1111X2222");
		const char *schr1 = string("X0000X1111X2222X");
		printf("S1:%s\n", strrchr(schr0, 88));
		printf("U1:%s\n", ft_strrchr(schr0, 88));
		printf("S2:%s\n", strrchr(schr1, 88));
		printf("U2:%s\n", ft_strrchr(schr1, 88));
		printf("S3:%s\n", strrchr(schr0, 87));
		printf("U3:%s\n", ft_strrchr(schr0, 87));
		printf("S4:-->%s<--\n", strrchr(schr0, 0));
		printf("U4:-->%s<--\n", ft_strrchr(schr0, 0));
		printf("S5:-->%s<--\n", strrchr("", '\0'));
		printf("U5:-->%s<--\n", ft_strrchr("", '\0'));
	}

	if (test("ft_isascii")){
		title("ft_isascii");
		printf("S:%d\n", isascii(88));
		printf("U:%d\n", ft_isascii(88));
		printf("S:%d\n", isascii(248));
		printf("U:%d\n", ft_isascii(248));
	}

	if (test("ft_isalpha")){
	title("ft_isalpha");
	printf("S:%d\n", isalpha('C'));
	printf("U:%d\n", ft_isalpha('C'));
	printf("S:%d\n", isalpha('3'));
	printf("U:%d\n", ft_isalpha('3'));
	}

	if (test("ft_isdigit")){
	title("ft_isdigit");
	printf("S:%d\n", isdigit('C'));
	printf("U:%d\n", ft_isdigit('C'));
	printf("S:%d\n", isdigit('3'));
	printf("U:%d\n", ft_isdigit('3'));
	}

	if (test("ft_strjoin")){
		title("ft_strjoin");
		const char *sj1 = string("12345");
		const char *sj2 = string("67890");
		printf("U(only):%s\n", ft_strjoin(sj1, sj2));
		printf("expectd:1234567890\n");
	}

	if(test("ft_substr")){
		title("ft_substr");
		char	str[] = "lorem ipsum dolor sit amet";
		char const *ss1 = string("0123456789");
		printf("U1(only):%s\n", ft_substr(ss1, 0, 3));
		printf("expected:012\n");
		printf("U2(only):%s\n", ft_substr(ss1, 2, 5));
		printf("expected:23456\n");
		printf("U3(only):%s\n", ft_substr(ss1, 7, 3));
		printf("expected:789\n");
		printf("U4(only):%s\n", ft_substr(ss1, 6, 6));
		printf("expected:6789\n");
		printf("U5(only):--><--%s\n", ft_substr(ss1, 1, 0));
		printf("expected:--><-- (empty)\n");
		printf("U6(only):%s\n", ft_substr(ss1, 1, 1));
		printf("expected:1\n");
		printf("U7(only):%s\n", ft_substr(ss1, 0, 1));
		printf("expected:0\n");
		printf("U8(only):%s\n", ft_substr(ss1, 9, 1));
		printf("expected:9\n");
		printf("U9(only):%s\n", ft_substr(ss1, 11, 1));
		printf("expected:(null)\n");

		printf("U10 only:%s\n", ft_substr(str, 0, 10));
		printf("U11 only:%s\n", ft_substr(str, 7, 10));
		printf("U12 only:%s\n", ft_substr(str, 7, 0));
		printf("U13 only:%s\n", ft_substr(str, 0, 0));
	}

	if(test("ft_strtrim")){
		title("ft_strtrim");
		char const *sti = string("XYXZXabcZXYXX");
		char const *stc0 = string("XYZ");
		char const *stc1 = string("X");
		char const *stc2 = string("XY");
		printf("U1(only):%s\n", ft_strtrim(sti, stc0));
		printf("expected:abc\n");
		printf("U2(only):%s\n", ft_strtrim(sti, stc1));
		printf("expected:YXZXabcZXY\n");
		printf("U2(only):%s\n", ft_strtrim(sti, stc2));
		printf("expected:ZXabcZ\n");
		printf("U3(only):%s\n", ft_strtrim(sti, "QW"));
		printf("expected:XYXZXabcZXYXX\n");
	}

	if(test("ft_atoi")){
		title("ft_atoi");
		printf("S1:%d\n", atoi("123"));
		printf("U1:%d\n", ft_atoi("123"));
		printf("S2:%d\n", atoi("-123"));
		printf("U2:%d\n", ft_atoi("-123"));
		printf("S3:%d\n", atoi(" + 123  "));
		printf("U3:%d\n", ft_atoi(" + 123  "));
		printf("S4:%d\n", atoi("  - 123  "));
		printf("U4:%d\n", ft_atoi("  - 123  "));
		printf("S5:%d\n", atoi("  -123  "));
		printf("U5:%d\n", ft_atoi("  -123  "));
		printf("S6:%d\n", atoi("546:5"));
		printf("U6:%d\n", ft_atoi("546:5"));
		printf("S7:%d\n", atoi("+548"));
		printf("U7:%d\n", ft_atoi("+548"));
		printf("S8:%d\n", atoi("\t\n\r\v\f  469 \n"));
		printf("U8:%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
		printf("S9:%d\n", atoi("\n\n\n  -46\b9 \n5d6"));
		printf("U9:%d\n", ft_atoi("\n\n\n  -46\b9 \n5d6"));
	}

	if(test("ft_calloc")){
		title("ft_calloc");
		printf("calloc:%p <-- must be some address... not good test\n", ft_calloc(3,3));
	}

	if(test("ft_isprint")){
		title("ft_isprint");
		printf("-->Check grademe!\n");
	}

	if(test("ft_memcmp")){
		title("ft_memcmp");
		printf("-->Check grademe!\n");
	}

	if(test("ft_strlcat")){
		title("ft_strlcat");
		printf("-->Check grademe!\n");
	}
	
	if(test("ft_strncmp")){
		title("ft_strncmp");
		printf("-->Check grademe!\n");
	}

	if(test("ft_tolower")){
		title("ft_tolower");
		printf("-->Check grademe!\n");
	}

	if(test("ft_toupper")){
		title("ft_toupper");
		printf("-->Check grademe!\n");
	}

	if(test("ft_itoa")){
		title("ft_itoa");
		printf("%d->%s\n", 123, ft_itoa(123));
		printf("%d->%s\n", -123, ft_itoa(-123));
		printf("%d->%s\n", 1230, ft_itoa(1230));
		printf("%d->%s\n", -1230, ft_itoa(-1230));
		printf("%d->%s\n", 100, ft_itoa(100));
		printf("%d->%s\n", -100, ft_itoa(-100));
		printf("%d->%s\n", 0, ft_itoa(0));
		printf("%d->%s\n", -0, ft_itoa(-0));
		printf("%d->%s\n", 10, ft_itoa(10));
		printf("%ld->%s\n", -2147483648, ft_itoa(-2147483648));
	}


//	if(test("ft_split")){
		title("ft_split");
//		char const *spls = string("123XabcX456Xdef");
		char **spl;
		int o;
		//= ft_split("12XabcX3456Xdefgh", 'X');
		

char **spl0 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
//	o = 0;
//		while (spl[o])
//		{
//			printf("%d >>%s\n",o,spl[o]);
//			o++;
//		}
char **spl1 = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
//	o = 0;
//		while (spl[o])
//		{
//			printf("%d >>%s\n",o,spl[o]);
//			o++;
//		}
char **spl2 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
//	o = 0;
//		while (spl[o])
//		{
//			printf("%d >>%s\n",o,spl[o]);
//			o++;
//		}
char **spl3 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
//	o = 0;
//		while (spl[o])
//		{
//			printf("%d >>%s\n",o,spl[o]);
//			o++;
//		}



//	}

	return (0);
}

//"238475238475" '\0'
//'X'
