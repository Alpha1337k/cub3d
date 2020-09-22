/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 20:54:32 by okruitho      #+#    #+#                 */
/*   Updated: 2020/09/22 22:31:13 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include "../../printf/ft_printf.h"
# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"
# include "../../minilibx-master/mlx.h"

# define RAD 0.0174532925
# define FOV 60

# ifndef LINUX
#  define LINUX 0
# endif

# ifndef LEGACY
#  define LEGACY 0
# endif

# if LINUX == 1
#  define KEYPRESS_W 119
#  define KEYPRESS_A 97
#  define KEYPRESS_S 115
#  define KEYPRESS_D 100
#  define KEYPRESS_L 65363
#  define KEYPRESS_R 65361
#  define KEYPRESS_ESC 65307
# else
#  define KEYPRESS_W 13
#  define KEYPRESS_A -1
#  define KEYPRESS_S 1
#  define KEYPRESS_D 2
#  define KEYPRESS_L 124
#  define KEYPRESS_R 123
#  define KEYPRESS_ESC 53
# endif

typedef enum	e_bool
{
	ERROR = -1,
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef enum	e_wdir
{
	ER = -1,
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	SP = 4
}				t_wdir;

typedef	struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_rgb;

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef	struct	s_vec3
{
	int			x;
	int			y;
	int			z;
}				t_vec3;

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef	struct	s_cast
{
	double		len;
	int			x_of;
	t_wdir		dir;
}				t_cast;

typedef struct	s_tex
{
	t_img		i;
	t_vec2		p;
}				t_tex;

typedef struct	s_vec2_d
{
	double		x;
	double		y;
}				t_vec2_d;

typedef	struct	s_map
{
	int			height;
	int			width;
	char		**val;
	int			status;
	char		*unp;
}				t_map;

typedef struct	s_sprite
{
	t_vec2		pos;
	double		dist;
}				t_sprite;

typedef struct	s_dda_sprite
{
	t_vec2		spritepos;
	t_vec2		mappos;
	int			*spriteorder;
	double		*spritedist;
	t_vec2_d	spritexy;
	double		invdet;
	t_vec2_d	transform;
	t_vec2		spritescreen;
	int			movescreen;
	int			tex_x;

}				t_dda_sprite;

typedef struct	s_dda_wall
{
	double		camera_x;
	t_vec2_d	raydir;
	t_vec2		mappos;
	t_vec2		step;
	int			side;
	t_vec2_d	sidedist;
	t_vec2_d	deltadist;
	double		perpdist;
	double		wallx;

}				t_dda_wall;

typedef struct	s_meta
{
	char		*arg;
	t_vec2_d	plane;
	t_vec2_d	dir;
	double		angle;
	t_bool		init;
	int			fc[2];
	int			keydown[8];
	t_img		i[2];
	t_map		map;
	t_tex		tx[5];
	t_vec2		res;
	t_vec2_d	pos;
	double		*z_buf;
	t_sprite	*sprite;
	int			spritecount;
	void		*mlx;
	void		*win;
}				t_meta;

/*
** Printing functions
*/
void			ft_print_map(t_meta *md);
void			ft_print_map_flood(char **map);
void			ft_print_meta(t_meta *md);

/*
**	Parsing / init functions
*/
t_map			ft_get_map(char *line, int fd);
t_meta			ft_parse_data(char *path, t_meta md);
int				ft_init_flood(t_meta *md);
void			ft_init_mlx(t_meta *md);
t_img			ft_load_frame(t_meta *md);
int				ft_check_input(t_meta *md);
t_tex			ft_load_img(t_meta *md, char *str);
t_img			ft_load_frame(t_meta *md);
void			ft_init_mlx(t_meta *md);
void			ft_set_pos(t_meta *md);
void			ft_set_pos_ang(t_meta *md, char val);
void			ft_get_spritepos(t_meta *md);

/*
** Functions that free etc.
*/
void			ft_freemap(char **map, int height);
void			ft_reset_md(t_meta *md);
int				ft_exit(t_meta *md);
int				ft_throw_error(char *s, t_meta *md);

/*
** Rgb functions
*/
int				ft_rgb_to_int(t_rgb color);
unsigned int	ft_rtoi(char *s);
unsigned int	ft_get_color(char *line);

/*
** Key Functions
*/
int				ft_set_keydown(int key, t_meta *md);
int				ft_set_keyup(int key, t_meta *md);
int				ft_move_player(t_meta *md);
void			ft_turn_right(t_meta *md);
void			ft_turn_left(t_meta *md);

/*
** Conversions
*/
t_vec2_d		ft_atc(double ang);
t_vec2			ft_vecmrg(int x, int y);

/*
** Drawing
*/
void			ft_draw_walls(t_meta *md, t_img *img);
void			ft_draw_rectangle(t_vec2 c1, t_vec2 c2, int clr, t_img *img);
void			ft_pixel_put(t_img *data, int x, int y, int color);
int				ft_render(t_meta *md);
void			ft_draw_ray(t_vec2 t, t_cast cast, t_img *img, t_meta *md);
void			ft_draw_wall_part(t_vec3 c, t_cast cast, t_img *img,\
					t_meta *md);
void			ft_save_bmp(t_img *img, t_meta *md);
t_cast			ft_cast_ray(t_meta *md, t_cast *sprite, t_vec2_d dir, \
					t_vec2 *t);
void			ft_draw_vline(int x, t_vec2 c, t_img *img, t_meta *md);
t_cast			ft_get_cast_data(t_meta *md, t_vec2_d *ray, t_vec2 *t, int spr);

/*
** Drawing DDA
*/
void			ft_dda_walls(t_meta *md, t_img *img);
void			ft_dda_sprites(t_meta *md, t_img *img);
void			ft_calculate_dda(t_dda_wall *dw, t_meta *md, t_vec3 *coords);
void			ft_setup_dda(t_dda_wall *dw, t_meta *md);
void			ft_dda(t_dda_wall *dw, t_meta *md);
/*
** Libft Addons?
*/
char			*ft_strnjoin(char *s1, char *s2, int n);
int				ft_strclen(char *s, char c);
char			*ft_strldup(const char *s1, int n);
long long		ft_atol(const char *str);

#endif
