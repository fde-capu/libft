/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:40:13 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 23:09:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_LIBFT_H
# define TYPES_LIBFT_H

typedef char* str;

typedef struct			s_list
{
	void				*content;
	struct s_list		*nx;
}						t_list;

typedef struct			s_rgb
{
	unsigned char		a;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_rgb;

typedef unsigned char	t_bol;

/*
** BMP related:
*/

typedef struct			s_bmfh
{
	unsigned short		bftype;
	unsigned int		bfsize;
	unsigned short		zeros1;
	unsigned short		zeros2;
	unsigned int		bfoffs;
}						t_bmfh;

typedef struct			s_bmih
{
	unsigned int		bisize;
	int					biwidth;
	int					biheight;
	unsigned short		biplanes;
	unsigned short		bpp;
	unsigned int		bicompress;
	unsigned int		bisizeimg;
	int					bixppmeter;
	int					biyppmeter;
	unsigned int		binumofcolors;
	unsigned int		biimportantcolors;
}						t_bmih;

typedef struct			s_rgbquad
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		z;
}						t_rgbquad;

typedef struct			s_bmp
{
	t_bmfh				file_header;
	t_bmih				info_header;
}						t_bmp;

typedef struct			s_dbl
{
	double				d;
	struct s_dbl		*nx;
	struct s_dbl		*last;
}						t_dbl;

typedef struct			s_matrix
{
	int					m;
	int					n;
	struct s_matrix		*nx;
	struct s_matrix		*pv;
	t_dbl				*i;
}						t_mat;

typedef t_mat			t_vec;

typedef struct			s_matrix_of_vectors
{
	int					m;
	int					n;
	t_vec				*i;
}						t_mvec;

typedef struct			s_triangle
{
	t_vec				*a;
	t_vec				*b;
	t_vec				*c;
	t_vec				*n;
	t_vec				*o;
	t_rgb				rgb;
	struct s_triangle	*nx;
}						t_tri;

/*
**struct s_triangle	*trans;
*/

typedef struct			s_pimitive
{
	int					type;
	t_vec				*o;
	t_vec				*n;
	double				h;
	double				d;
	t_rgb				rgb;
	struct s_pimitive	*trans;
	struct s_pimitive	*nx;
}						t_prm;

typedef struct			s_camera
{
	t_vec				*o;
	t_vec				*p;
	t_vec				*n;
	t_vec				*left;
	double				fov;
	struct s_camera		*nx;
}						t_cam;

typedef struct			s_amb_light
{
	double				f;
	t_rgb				rgb;
}						t_alt;

typedef struct			s_light
{
	t_vec				*o;
	double				f;
	t_rgb				rgb;
	struct s_light		*nx;
}						t_lht;

typedef struct			s_win {
	char				*title;
	int					height;
	int					width;
}						t_win;

typedef struct			s_img {
	int					height;
	int					width;
	char				*address;
	int					bpp;
	int					endian;
	int					line_l;
}						t_img;

typedef struct			s_scene
{
	t_vec				*resolution;
	t_alt				ambient;
	t_cam				*cam_active;
	t_cam				*cam_list;
	t_lht				*lights;
	t_prm				*primitives;
	t_tri				*faces;
}						t_scn;

typedef struct			s_mrt {
	void				*mlx;
	void				*win;
	void				*img;
	t_scn				*scn;
	t_win				window;
	t_img				i;
	t_vec				*cursor;
	char				*icursor;
	t_rgb				color;
}						t_mrt;

typedef struct			s_ray {
	t_vec				*a;
	t_vec				*b;
	t_vec				*d;
}						t_ray;

typedef struct			s_intersection {
	t_prm				*primitive;
	t_tri				*triangle;
	t_ray				*ray;
	double				t;
	t_vec				*phit;
	t_vec				*n;
}						t_hit;

#endif
