/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:22:40 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/21 17:36:05 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "includes/libft.h"
# include "includes/mlx.h"
# include <math.h>
# include <fcntl.h>

# define WIN_W 1000
# define WIN_H 1000
# define TEX_H 64
# define TEX_W 64
# define MAP_SIZE 16
# define SPAWN 9

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_PRESS_MASK (1L<<0)
# define KEY_RELEASE_MASK (1L<<1)
# define WIN_DESTROY 0
# define WIN_DESTROY_MASK 0
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define R 15
# define T 17
# define ESC 53

typedef double		t_darr[2];
typedef int			t_iarr[2];

typedef struct		s_img
{
	void		*ptr;
	int			bpp;
	int			line_size;
	int			endian;
	char		*pxl;
}					t_img;

typedef struct		s_env
{
	void		*mlx;
	void		*wnd;
	t_img		*img;
	t_img		texture[8];
	int			map[MAP_SIZE][MAP_SIZE];
	int			key_state[4];
	int			textswitch;
	int			colors[4];
	t_darr		pos;
	t_darr		dir;
	t_darr		plan;
	t_darr		ray_pos;
	t_darr		ray_dir;
	t_darr		side_dist;
	t_darr		delta_dist;
	t_darr		floor_lim;
	t_darr		floor;
	t_iarr		map_coord;
	t_iarr		screen_coord;
	t_iarr		step;
	t_iarr		line_lim;
	t_iarr		tex;
	int			colision;
	int			line_h;
	int			num_tex;
	int			side;
	int			color;
	double		perp_dist;
	double		cam_pos;
	double		movespd;
	double		rotspd;
	double		wall_pos;
	double		wall_dist;
	double		current_dist;
	int			skybox_off;
}					t_env;

t_img			*new_img(t_env *e, int w, int h);
void			img_put_pixel(t_env *e, int x, int y, int color);
void			cast_ray(t_env *e, int x);
void			draw_texture(t_env *e);
void			draw_view(t_env *e);
void			draw_pnj(t_env *e);
void			init_texture(t_env *e);
int				key_hook_press(int key, t_env *e);
int				key_hook_release(int key, t_env *e);
int				refresh_window(t_env *e);
void			init_map(t_env *e);
void			wexit(t_env *e);
int				img_get_pixel(t_env *e, t_img *img, int x, int y);

void			print_map(t_env *e);
void			test_tex(t_env *e);
void			print_mini_map(t_env *e);
#endif
