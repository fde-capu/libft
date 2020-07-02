/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:40:13 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/02 09:31:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_LIBFT_H
# define TYPES_LIBFT_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*nx;
}					t_list;

typedef struct		s_int2d
{
	int				x;
	int				y;
}					t_i2d;

typedef struct		s_int3d
{
	int				x;
	int				y;
	int				z;
}					t_i3d;

typedef struct		s_double2d
{
	double			x;
	double			y;
}					t_d2d;

typedef struct		s_double3d
{
	double			x;
	double			y;
	double			z;
}					t_d3d;

typedef struct		s_rgb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef unsigned char	t_bol;

/*
** BMP related:
*/

typedef struct		s_bmfh
{
	unsigned short	bftype;
	unsigned int	bfsize;
	unsigned short	zeros1;
	unsigned short	zeros2;
	unsigned int	bfoffs;
}					t_bmfh;

typedef struct		s_bmih
{
	unsigned int	bisize;
	int				biwidth;
	int				biheight;
	unsigned short	biplanes;
	unsigned short	bpp;
	unsigned int	bicompress;
	unsigned int	bisizeimg;
	int				bixppmeter;
	int				biyppmeter;
	unsigned int	binumofcolors;
	unsigned int	biimportantcolors;
}					t_bmih;

typedef struct		s_rgbquad
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	z;
}					t_rgbquad;

typedef struct		s_bmp
{
	t_bmfh			file_header;
	t_bmih			info_header;
}					t_bmp;

typedef struct		s_dbl
{
	double			d;
	struct s_dbl	*nx;
}					t_dbl;

typedef struct		s_matrix
{
	t_dbl			*i;
	int				m;
	int				n;
}					t_mat;

typedef t_mat		t_vec;

#endif
