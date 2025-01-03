/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:19:33 by fde-capu          #+#    #+#             */
/*   Updated: 2022/02/27 21:22:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** v0.0.1
** Incompatibility!
** ft_chrinset used to be `(char *, char *)`, now is `(char, char *)`.
** Change previous version to `ft_strchrinset (char *, char *)` to fix it.
**
** !!!! Attention! This file has <math.h> !!!!!
*/

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

# include "defines_libft.h"
# include "types_libft.h"
# include "debug.h"
# include "keys.h"
# include "common.h"


/*
** JSON related.
*/

# define NEW_LINE "\n"
# define LOG_FD 1

typedef struct node
{
	str				name;
	str				value;
	struct node		*up;
	struct node		*nx;
	struct node		*dn;
	struct node		*pv;
} node;

typedef struct json
{
	node*	base_node;
} json;

str node_raw_path(json* data, node* nd);
void logger_rose(node *n);
json* json_new();
str	json_get(json* data, str path);
str json_put(json* data, str path);
void json_clear(json *this);
str json_del(json* data, str path);
str json_render(json* data);
str json_post(json* data, str path);
void logger(int argc, ...);
str* path_split(str path);
str json_render_as_attr(node* h);
str json_render_node(node* h, int go_dn, int show_name);
str correct_quotes(str in);
str no_reserved(str path);
node* node_goto(json* data, str path);
node* node_goto_force(json* data, str path);
void nodelist_clear(node* n);
void node_del(node* n);
node* node_new(str name, str value, node* up, node* nx, node* dn, node* pv);
node* node_last_dn(node* h);
node* node_last_nx(node* h);
node* node_goto_soft(json* data, str path);





bool			validate_args(int argc, char **argv, int argc_min, int argc_max, char *valid_args_csv);
bool			validate_args_regex(int argc, char **argv, int argc_min, int argc_max, char *valid_args_regex_pipesv);
t_rgb			light_decay(t_lht *light, t_hit *hit, t_rgb base);
int				bad_file_extension(char *fn, char *required_extension);
long long		ft_abs(long long value);
double			ft_abs_double(double value);
unsigned int	ft_argbtoi(t_rgb rgb);
char			*ft_args(int argc, char **argv, char *test);
double			ft_atod(const char *str);
long long		ft_atoi(const char *str);
t_rgb			ft_atorgb(char *str);
long long		ft_btod(char *nbr, int b_from);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_ceil(double d);
char			*ft_check(const char *str, char *reg);
bool			ft_check_full(const char *str, char *reg);
int				ft_chrinset(char r, char const *set);
int				ft_chrsame(char a, char b);
char			*ft_chrtostr(char chr);
char			*ft_convert_base(const void *bdata, ...);
unsigned int	ft_countdigits(long long number);
unsigned int	ft_countdigits_ibase(long long number, unsigned int base);
void			ft_die(const char *msg, int err);
char			*ft_dtoa(double d);
char			*ft_dtob(long long n, int b_to);
int				ft_enclosure(char *io, char h);
char			*ft_findstr(char *str, char c);
char			*ft_get_word(char *line);
int				ft_head_read(char **h, char *r, char *key);
void			ft_init(void);
char			*ft_inside(char *h);
char			*ft_inskip(char *h);
int				ft_insp_count(char *h, char x);
char			**ft_insplit(const char *str, char x);
int				ft_is_comment(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isnumber(char *str);
int				ft_isprint(int c);
void			ft_print_stdout(const char *str);
void			ft_print_x(char *str);
void			ft_print(const char *str);
int				ft_print_and_return_int(char *message, int return_value);
int				ft_print2_and_return_int(char *messageA, char *messageB, int return_value);
int				ft_isupper(int c);
char			*ft_itoa(int n);
t_rgb			ft_itoargb(unsigned int i);
t_rgb			ft_itobgra(unsigned int i);
char			*ft_join(char **split);
char			*ft_lastchar(char *str);
int				ft_lastchar_eq(char *str, char chr);
char			*ft_lcase(const char *str);
char			*ft_lltoa(signed long long n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
char			*ft_ltoa(long n);
void			ft_max2d(int *x, int *y, int x_lim, int y_lim);
void			*ft_memcat(void *m1, void *m2, int s1, int s2);
void			*ft_memcatx(void *m1, void *m2, int s1, int s2);
void			*ft_memcatxl(void *m1, void *m2, int s1, int s2);
void			*ft_memcatxr(void *m1, void *m2, int s1, int s2);
void			*ft_memccpy(void *dst, const void *src, \
					int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
double			ft_pow(double a, int e);
char			*ft_ptoa(void *p);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
void			ft_putstr_nl(char *s);
char			*ft_removequotes(char *quoted);
char			*ft_repchar(char c, unsigned int rpt);
void			ft_repchar_fd(char c, unsigned int rpt, int fd);
t_rgb			ft_rgb(unsigned char a, \
					unsigned char r, unsigned char g, unsigned char b);
char			*ft_rgbtoa(t_rgb rgb);
int				ft_rgbtoi(t_rgb rgb);
char			**ft_split(char const *s, char c);
char			**ft_split_set(char const *s, const char *c);
size_t			ft_strarrlen(char **s);
int				ft_strbegins(const char *str, const char *beg);
char			*ft_strcat(const char *dst, const char *src);
str				ft_strcat2d(str* s);
char			*ft_strcatchrx(char *dst, char *c);
char			*ft_strcatx(char *dst, char *src);
char			*ft_strcatxl(char *s1, char *s2);
char			*ft_strcatxr(char *s1, char *s2);
char			*ft_strcatxx(char *s1, char *s2);
str				ft_strcat_variadic(int argc, ...);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(char *str, char c);
char			*ft_strchrcat(const char *dst, const char src);
int				ft_strchrinset(char *t, char const *sset);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
void			ft_strfree2d(char **str);
bool			ft_strfree2d_and_return_bool(char **str, bool ret_val);
int				ft_stridentical(const char *s1, const char *s2);
int				ft_stridentical_insensitive(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
str				ft_strjoin2d(str* s, str divisor);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_str(char *str);
char			*ft_strnchr(char *str, char c);
char			*ft_strnew(void);
char			*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *src);
char			*ft_strstr(const char *a, const char *b);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strtrimx(char *s1, char *set);
char			*ft_strtrunc(char *dst, char trunc);
char			*ft_strtrunc_pos(char *str, int pos);
char			*ft_strx(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_trim(char *str);
double			ft_trig(double a_is_to, double b_as, double this_is_to_x);
char			*ft_ucase(const char *str);
char			*ft_uctoa(unsigned char uc);
char			*ft_uitoa(unsigned int n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_ultoa(unsigned long n);
char			*ft_ultoa(unsigned long n);
char			*ft_vtoa(t_vec *vec);
char			ft_whichar(const char *s, int x);
void			*ft_x(void *a1, void *a2);
void			*ft_xlloc(void *arg1, void *arg2);
u_int8_t		ft_bit8_get(u_int8_t *data, u_int8_t bit);
void			ft_bit8_set(u_int8_t *data, u_int8_t bit, u_int8_t val);
void			ft_bit8_tog(u_int8_t *data, u_int8_t bit);
char			*ft_bit8_str(u_int8_t data);
char			*ft_removequotes(char *quoted);
void			primitive_zzz_position(t_prm *cyl, t_ray *ray);
void			triangle_zzz_position(t_tri *tri);
void	triangle_rotate_in_place(t_tri *tri, t_mat *rot);
int				loop_2d(int x, int y);
void			hit_set_primitive(t_hit *hit, double test, t_prm *primitive, \
					t_ray *ray);
void			hit_set_triangle(t_hit *hit, double test, t_tri *triangle, \
					t_ray *ray);
void			quadratic_build(t_ray *ray, double *a, double *b, \
					double *c);
int				hit_inside_sphere(t_ray *ray, t_prm *prm);

/*
** lstdbl
*/

t_dbl			*lstdbl_addlast(t_dbl *h, double d);
t_dbl			*lstdbl_copy(t_dbl *h);
void			lstdbl_destroy(t_dbl *dbl);
t_dbl			*lstdbl_last(t_dbl *h);
void			lstdbl_mult_element(t_dbl *ld, int e, int m);
t_dbl			*lstdbl_new(double val);
double			lstdbl_pop(t_dbl *h);

/*
** Regex related.
*/

int				rgx_fun_in(int fun);
void			rgx_maybe_free(char *blk, int fun);
int				rgx_function_n(char *rh);
char			*rgx_chk_function(int mode, char *sh, char *blk);
void			rgx_set_rep(int *mm, char *mod);
char			*rgx_sk_mod(char *mod);
int				rgx_mm_manual(int pos, char *keys);
void			rgx_mm_mod(int *mm, int oblig, int optio);

/*
** Verboses:
*/

void			verb_cam(t_scn *scn);
void			verb_cam_active(t_scn *scn);
void			verb_faces(t_scn *scn);
void			verb_lights(t_scn *scn);
void			debug_primitive(t_prm *h);
void			verb_primitives(t_scn *scn);
void			verbose_scene(t_scn *scn);

/*
** Math related:
*/

void			primitive_scale(t_prm *prm, double factor);
void			triangle_scale(t_tri *tri, double factor);
void			triangle_zzz_position(t_tri *tri);
t_prm			*primitive_copy(t_prm *prm);
void			triangle_rotate_in_place(t_tri *tri, t_mat *rot);
void			primitive_rotate_in_place(t_prm *prm, t_mat *rot);
t_vec			*triangle_center(t_vec *a, t_vec *b, t_vec *c);
t_mat			*axis_angle_rotation(t_vec *axis, double theta);
t_vec			*vector_halfway(t_vec *a, t_vec *b);
t_vec			*vector_inverse_translate(t_vec *vec, t_vec *trans);
t_vec			*vector_origin_scale(t_vec *a, t_vec *o, double factor);
void			vector_append_val(t_vec *vec, double val);
t_vec			*vector_build(int len, ...);
t_vec			*vector_copy(t_vec *a);
t_vec			*vector_cross_product(t_vec *x, t_vec *y);
void			vector_destroy(t_vec *vec);
double			vector_dot_product(t_vec *v1, t_vec *v2);
t_vec			*vector_empty(int len);
int				vector_equal(t_vec *a, t_vec *b);
double			vector_get_element(t_vec *vec, int i);
double			vector_magnitude(t_vec *v);
t_vec			*vector_matrix_multiply(t_vec *left, t_mat *right);
void			vector_multiply_element(t_vec *vec, int elem, double factor);
t_vec			*vector_new(void);
void			vector_normalize(t_vec *mv);
int				vector_parallel(t_vec *x, t_vec *y);
double			vector_pop(t_vec *vec);
void			vector_put_element(t_vec *vec, int pos, double d);
int				vector_range_check_boundaries(t_mat *m, t_vec *range);
void			vector_range_fix(t_vec *range);
t_vec			*vector_scalar_multiply(t_vec *a, double scalar);
t_vec			*vector_scalar_sum(t_vec *vec, double val);
t_vec			*vector_scale(t_vec *vec, t_vec *xyz);
t_vec			*vector_subtract(t_vec *a, t_vec *b);
t_vec			*vector_sum(t_vec *a, t_vec *b);
void			vector_transform(t_vec **vec, t_mat *trans);
t_mat			*vector_transpose(t_vec *v);
t_vec			*vector_translate(t_vec *vec, t_vec *xyz);
double			vector_vector_angle_deg(t_vec *x, t_vec *y);
double			vector_vector_angle_rad(t_vec *x, t_vec *y);
t_vec			*vectorx(t_vec *old, t_vec *new);
t_vec			*matvec_get_element(t_mvec *mv, int i, int j);
void			matvec_insert_at_pos(t_mvec *mv, int i, int j, t_vec *vec);
void			matvec_destroy(t_mvec *mat);
t_mvec			*matvec_new(void);
t_vec			*ft_atov(char *str);
int				is_normalized(t_vec *vec);
t_mat			*matrix_adjoint(t_mat *m);
t_mat			*matrix_build(int m, int n, ...);
t_mat			*matrix_checkers_sign(t_mat *a);
t_mat			*matrix_copy(t_mat *a);
void			matrix_destroy(t_mat *mat);
double			matrix_determinant(t_mat *a);
t_mat			*matrix_diagonal(t_vec *dvec);
t_mat			*matrix_empty(int m, int n);
double			matrix_get_element(t_mat *mat, int i, int j);
t_mat			*matrix_get_line(t_mat *m, int i);
t_vec			*matrix_get_line_transposed(t_mat *m, int i);
t_vec			*matrix_get_vector(t_mat *m, int j);
t_dbl			*matrix_goto_element(t_mat *mat, int m, int n);
t_mat			*matrix_identity(int s);
int				ft_mrt_init_img(t_mrt *mrt);
t_mat			*matrix_inverse(t_mat *a);
t_mat			*matrix_matrix_multiply(t_mat *left, t_mat *right);
t_mat			*matrix_minor(t_mat *a, int i, int j);
t_mat			*matrix_new(void);
t_mat			*matrix_new_mn(int m, int n);
t_mat			*matrix_of_cofactors(t_mat *a);
t_mat			*matrix_of_minors(t_mat *a);
t_mat			*matrix_of_vectors_transposed(t_vec *v1, t_vec *v2, t_vec *v3);
void			matrix_put_element(t_mat *dst, int i, int j, double d);
void			matrix_put_matrix(t_mat *dest, t_mat *ref, int i, int j);
t_mat			*matrix_scalar_multiply(t_mat *b, double s);
void			matrix_screen(t_mat *dst, t_mat *src);
t_mat			*matrix_sum(t_mat *a, t_mat *b);
void			matrix_switch_elements(t_mat *mat, t_vec *tvec);
void			matrix_transform(t_mat **mat, t_mat *trans);
t_mat			*matrix_transpose(t_mat *a);
t_vec			*matrix_vector_multiply(t_mat *left, t_vec *right);
t_mat			*matrixx(t_mat *old, t_mat *new);
char			*primitive_type_number(int type);
t_ray			*ray_build(t_vec *a, t_vec *b);
t_ray			*ray_copy(t_ray *src);
void			ray_verb(char *str, t_ray *ray);
void			ray_transform(t_ray *ray, t_mat *trn);
void			ray_destroy(t_ray *ray);
double			hit_sphere(t_ray *ray, t_prm *sphere);
double			hit_triangle(t_ray *ray, t_tri *tri);
t_vec			*triangle_normal(t_tri *tri);
t_vec			*hit_triangle_crosshit(t_vec *hit, t_vec *tri_a, t_vec *tri_b);
void			destroy_hit_triangle(t_vec *hit, t_vec *pos[3], \
					t_prm *pl, t_vec *v);
double			hit_minimal(double t);
double			hit_disc(t_ray *ray, t_prm *disc);
t_vec			*hit_point(t_ray *ray, double t);
void			missing_up_gambiarra(t_vec *p, t_vec **v_up, t_vec **v_left);
double			hit_plane(t_ray *ray, t_prm *plane);
double			hit_cylinder(t_ray *ray, t_prm *cylinder);
double			hit_cylinder2(t_ray *ray, t_prm *cylinder);
int				inside_cylinder_bondaries(t_ray *ray, double t, \
					t_prm *cylinder);
t_vec			*intersect_cylinder_normal(t_hit *hit);
void			primitive_transform(t_prm *prm, t_mat *trn);
void			triangle_transform(t_tri *tri, t_mat *trn);
void			primitive_translate(t_prm *prm, t_mat *trn);
void			triangle_translate(t_tri *tri, t_mat *trn);
void			ray_translate(t_ray *ray, t_vec *trn);
void			vector_smash_z(t_vec *vec);
t_vec			*vector_normal_construct(t_vec *ori, t_vec *dest);
t_rgb			color_multiply(t_rgb ca, t_rgb cb);
t_rgb			color_normal(t_hit *hit);
t_rgb			ft_argb_multiply(t_rgb argb, double factor);
t_rgb			ft_argb_sum(t_rgb a, t_rgb b);
t_rgb			color_distance(t_hit *hit);
t_rgb			color_blend(t_rgb a, t_rgb b, double factor);
void			primitive_destroy(t_prm *lst);
void			intersect_phit(t_hit *hit);
void			*intersect_destroy(t_hit *hit);
double			hipo(double c1, double c2);
double			radtodeg(double rad);
double			quadratic_minor(double a, double b, double c);
double			quadratic_major(double a, double b, double c);
double			degtorad(double deg);
void			intersect_normal(t_hit *hit);
t_hit			*intersect_complements(t_hit *hit);
t_vec			*intersect_normal_triangle(t_hit *hit);
t_vec			*intersect_normal_generic_primitive(t_hit *hit);
void			triangle_destroy(t_tri *lst);
int				scene_destroy(t_scn *sc);
void			scn_free_list_lht(t_lht *lst);
void			scn_free_list_cam(t_cam *lst);
void			scn_free_list_prm(t_prm *lst);
void			scn_free_list_tri(t_tri *lst);
t_alt			amb_light_init(double f, t_rgb rgb);
t_cam			*cam_init(t_vec *o, t_vec *p, double fov);
t_scn			*scene_init(void);
t_lht			*light_init(t_vec *o, double f, t_rgb rgb);
t_prm			*sphere_init(t_vec *o, double d, t_rgb rgb);
t_prm			*plane_init(t_vec *o, t_vec *n, t_rgb rgb);
t_prm			*disc_init(t_vec *o, t_vec *n, double d, t_rgb rgb);
t_prm			*square_init(t_vec *o, t_vec *n, double h, t_rgb rgb);
t_prm			*cylinder_init(t_vec *o, t_vec *n, double h, double d);
t_tri			*triangle_init(t_vec *a, t_vec *b, t_vec *c, t_rgb rgb);
void			scn_add(int objtype, void *obj, t_scn *sc);
t_mat			*vector_vector_rotation_matrix(t_vec *v1, t_vec *v2);
double			vector_vector_distance(t_vec *a, t_vec *b);
void			intersect_normaltriangle(t_hit *hit);
void			primitive_zzz_position(t_prm *cyl, t_ray *ray);
t_rgb			color_add(t_rgb ca, t_rgb cb);
t_rgb			rgb_force(t_rgb rgb, double f);
unsigned int	color_force(t_rgb rgb, double f);
unsigned int	color_trace(t_mrt *mrt, t_hit *hit);
unsigned int	skybox(int x, int y);
t_rgb			color_ambient(t_mrt *mrt);
t_rgb			color_diffuse(t_lht *light, t_hit *hit);
t_rgb			color_specular(t_lht *light, t_hit *hit);
double			can_see_light(t_mrt *mrt, t_hit *hit, t_vec *l);
double			can_see_light_primitive(t_mrt *mrt, t_hit *hit, t_vec *l);
double			can_see_light_triangle(t_mrt *mrt, t_hit *hit, t_vec *l);
double			hit_primitive(t_prm *primitive, t_ray *ray);
double			ray_destroy_and_return(t_ray *ray, double val);
t_hit			*hit_new(double max);

#ifndef g_x
extern t_vec			*g_x;
extern t_vec			*g_y;
extern t_vec			*g_z;
extern t_mrt			*g_mrt;
#endif

int				ft_ternary_i(int x, int vt, int vf);
char			*ft_ternary_c(int x, char *vt, char *vf);
long long		freec_and_retll(char *f, long long r);

/*
** Debugs:
*/

int				debug_pass(void);
void			debug(char *str, char *val, int *ival);
void			debug_body(char *str, char *val, int ival);
void			debug_int(char *str, int ival);
void			debug_int2(char *str, int val, int val2);
void			subdebug_int(char *str, int ival, int subdeb);
void			subdebug_int2(char *str, int val, int val2, int subdeb);
void			debug_str(char *str, char *val);
void			debug_str2(char *str, char *val, char *val2);
void			debug_str_only(char *str);
void			debug_double(char *str, double val);
void			debug_double2(char *str, double val, double val2);
void			debug_rgb(char *str, t_rgb rgb);
void			debug_vector(char *str, t_vec *vec);
void			debug_str_add(char *str, void *add);
void			debug_str_str(char *str1, char *str2);
void			debug_t_dbl(char *str, t_dbl *dbl);
void			debug_matrix(char *str, t_mat *mat);
void			debug_matrix_2(t_mat *mat);
void			debug_matrix_of_vectors(char *str, t_mvec *mat);
void			debug_matrix_single_line(t_mat *mat);
void			debug_ray(char *str, t_ray *ray);

#endif
