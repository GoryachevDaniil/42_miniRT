/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:15:20 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/20 18:33:19 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef	struct	s_vec
{
	double			x;
	double			y;
	double			z;
}				t_vec;

typedef struct	s_ku
{
	double			k1;
	double			k2;
	double			k3;
	double			t1;
	double			t2;
	double			m1;
	double			m2;
	double			m_res;
	double			disc;
}				t_ku;

typedef struct	s_mlx
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}				t_mlx;

typedef	struct	s_color
{
	int				r;
	int				g;
	int				b;
}				t_color;

typedef	struct	s_objs
{
	int				id;
	t_vec			xyz;
	t_vec			xyz2;
	t_vec			xyz3;
	t_vec			xyz_n;
	t_color			color;
	double			sp_dm;
	double			sq_dl;
	double			cy_dm;
	double			cy_h;
	struct s_objs	*next;
}				t_objs;

typedef struct	s_cam
{
	int				id;
	t_vec			xyz;
	t_vec			xyz_n;
	int				fov;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_light
{
	int				id;
	t_vec			xyz;
	float			ratio;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_amb
{
	double			range;
	t_color			color;
}				t_amb;

typedef struct	s_res
{
	int				x;
	int				y;
}				t_res;

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_minirt
{
	int				i;
	int				k;
	int				x;
	int				y;
	int				local_color;
	char			*tabu;
	char			**split;
	char			**split_rgb;
	char			**split_xyz;
	char			**split_xyz_2;
	char			**split_xyz_3;
	char			**split_xyz_n;
	int				cam_count;
	int				amb_pars;
	int				res_pars;
	double			t_min;
	double			sp_r;
	double			intens;
	double			v_dot;
	t_ku			ku;
	t_vec			p;
	t_vec			n;
	t_vec			d;
	t_vec			d2;
	t_vec			l;
	t_res			res;
	t_res			center;
	t_amb			amb;
	t_cam			*m_cam;
	t_objs			*m_obj;
	t_list			*light;
	t_list			*objs;
	t_list			*cam;
	t_color			res_color;
	int				n_id;
	t_vec			vn;
	double			vn_r;
	void			*mlx;
	void			*win;
	t_list			*tmp;
	t_mlx			image;
	int				bmp;
	char			*flag;
	double			t1;
	double			t2;
	double			t_tmp;
}				t_minirt;

t_color			ft_light(t_minirt *rt, t_vec n, t_vec p, t_objs *main);
int				main(int argc, char **argv);
void			ft_inicializate_t_minirt(t_minirt *rt);
void			ft_open_rt_file(char *file, t_minirt *rt);
void			ft_make_rt_file(t_list **list, int size, t_minirt *rt);
void			ft_err_ex_minirt(t_minirt *rt, char *str);
void			ft_parser_rt(char *line, t_minirt *rt);
void			ft_parse_line(char *line, t_minirt *rt);
void			ft_parse_sp(char *line, t_minirt *rt);
void			ft_parse_pl(char *line, t_minirt *rt);
void			ft_parse_sq(char *line, t_minirt *rt);
void			ft_parse_cy(char *line, t_minirt *rt);
void			ft_parse_tr(char *line, t_minirt *rt);
void			ft_parse_res(char *line, t_minirt *rt);
void			ft_parse_amb(char *line, t_minirt *rt);
void			ft_parse_cam(char *line, t_minirt *rt);
void			ft_parse_light(char *line, t_minirt *rt);
void			ft_raytrace_start(t_minirt *rt);
void			ft_render(t_minirt *rt);
int				ft_traceray(t_minirt *rt, t_vec v1, t_vec v2);
void			ft_inter_search(t_minirt *rt, double tm, t_vec v1, t_vec v2);
void			ft_resault_light(t_minirt *rt, t_light *p_l, t_vec n, t_vec p);
double			ft_svet(t_light *p_l, t_vec n, t_vec p);
double			ft_if_bliki(t_minirt *rt, t_light *p_l, t_vec n, t_vec p);
double			ft_bliki(t_minirt *rt, t_light *p_l, t_vec n, t_vec p);
double			ft_ku_sphere(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2);
double			ft_ku_plane(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2);
double			ft_ku_square(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2);
double			ft_ku_cylinder(t_minirt *rt, t_objs *obj, t_vec o, t_vec d);
t_vec			ft_find_cy_t(t_minirt *rt, t_vec d, t_objs *obj, t_vec oc);
double			ft_ku_triangle(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2);
void			ft_p_n_sphere(t_minirt *rt, t_objs *obj, double t_min);
void			ft_p_n_plane(t_minirt *rt, t_objs *obj, double t_min);
void			ft_p_n_square(t_minirt *rt, t_objs *obj, double t_min);
void			ft_p_n_cylinder(t_minirt *rt, t_objs *obj, double t_min);
void			ft_p_n_triangle(t_minirt *rt, t_objs *obj, double t_min);
void			ft_choose_cam(t_minirt *rt);
void			ft_change_cam(t_minirt *rt);
t_vec			ft_cam_direction(t_minirt *rt, double x, double y);
t_vec			ft_canvas_to_viewport(t_minirt *rt, double x,
					double y, double z);
int				ft_cam_inside_obj(t_minirt *rt);
void			ft_check_normla_xyz(float nx, float ny, float nz, t_minirt *rt);
int				ft_check_split(char **arr);
int				ft_check_rt_file(char *argv);
void			ft_check_cam_count(t_minirt *rt);
void			ft_check_tr(t_minirt *rt, t_objs *tmp);
t_color			ft_check_rgb(t_minirt *rt, t_color color);
void			ft_check_rgb_2(int *r, int *g, int *b);
t_color			ft_make_color(char **arr, t_minirt *rt);
t_color			ft_c_k(t_color clr, double i);
t_color			ft_c_c(t_color c1, t_color c2);
t_color			ft_c_c_k(t_color c1, t_color c2, double kf);
t_color			ft_c_k_c_k(t_color c1, double k1, t_color c2, double k2);
int				ft_create_trgb(t_color color);
int				ft_key_comands(int keycode, t_minirt *rt);
int				ft_stop_it(void);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
t_vec			dev_v(t_vec vec, double s);
t_vec			sub_v(t_vec one, t_vec two);
t_vec			sum_v(t_vec one, t_vec two);
t_vec			cross_v(t_vec one, t_vec two);
double			dot_v(t_vec one, t_vec two);
double			len_v(t_vec vec);
t_vec			normalize_v(t_vec v);
t_vec			mult_v(double k, t_vec vec);
t_vec			ft_mat_vec(t_vec r, t_vec u, t_vec n, t_vec d);
t_vec			ft_make_vec(char **arr, t_minirt *rt);
int				ft_vec_cmp(t_vec v1, t_vec v2);
int				ft_ugl(t_vec l, t_vec n);
double			ft_atof_rt(char *str, t_minirt *rt);
int				ft_atoi_rt(char *str, t_minirt *rt);
void			ft_bzero(void *dest, size_t n);
void			*ft_calloc(unsigned num, size_t size);
int				ft_isalpha(int ch);
int				ft_isdigit(int ch);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_putstr(char *s);
char			**ft_split_set(char const *s, char *set);
char			**ft_split(t_minirt *rt, char const *s, char c);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_save_bmp_image(t_minirt *rt);
void			ft_free_array(char ***arr);
void			ft_free_arr(char **arr);
void			ft_free_all_split(t_minirt *rt);

#endif
