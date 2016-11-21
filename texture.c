/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:06:38 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/21 16:43:14 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_texture(t_env *e)
{
	char			*files[8];
	int				w;
	int				h;
	int				f;

	f = -1;
	files[3] = "textures/bluestone.xpm";
	files[0] = "textures/eagle.xpm";
	files[2] = "textures/greystone.xpm";
	//files[3] = "textures/mossy.xpm";
	files[1] = "textures/bricksx64.xpm";
	files[4] = "textures/wood.xpm";
	files[5] = "textures/redbrick.xpm";
	files[6] = "textures/skybox_dark.xpm";
	files[7] = "textures/barrel.xpm";
	while (++f < 7)
	{
		if ((e->texture[f].ptr = mlx_xpm_file_to_image(e->mlx,
						files[f], &w, &h)) != NULL)
			e->texture[f].pxl = mlx_get_data_addr(e->texture[f].ptr,
					&e->texture[f].bpp, &e->texture[f].line_size,
					&e->texture[f].endian);
		else
			ft_putendl("texture not found");
	}
}

void		draw_floor_and_sky(t_env *e)
{
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		img_put_pixel(e, e->screen_coord[0], y, img_get_pixel(e, &e->texture[6],
					e->screen_coord[0] + e->skybox_off, y));
		if (y > e->line_lim[1])
			img_put_pixel(e, e->screen_coord[0], y, 0x422001);
	}
}

void		draw_texture(t_env *e)
{
	draw_floor_and_sky(e);
	if ((e->num_tex = e->map[e->map_coord[0]][e->map_coord[1]] - 1) < 1)
		return ;
	e->wall_pos = (e->side == 0 || e->side == 1) ? e->ray_pos[1] + e->perp_dist
		* e->ray_dir[1] : e->ray_pos[0] + e->perp_dist * e->ray_dir[0];
	e->wall_pos -= floor(e->wall_pos);
	e->tex[0] = (int)(e->wall_pos * (double)TEX_W);
	e->tex[0] = (((e->side == 0 || e->side == 1) && e->ray_dir[0] > 0) ||
			((e->side == 2 || e->side == 3) && e->ray_dir[1])) ?
		TEX_W - e->tex[0] -1 : e->tex[0];
	while (e->line_lim[0] < e->line_lim[1])
	{
		e->tex[1] = (((e->line_lim[0] * 256 - WIN_H * 128 + e->line_h * 128)
					* TEX_H) / e->line_h) / 256;
		if (e->textswitch == 0)
			e->color = e->colors[e->side];
		else
			e->color = img_get_pixel(e, &e->texture[e->num_tex],
					e->tex[0], e->tex[1]);
		img_put_pixel(e, e->screen_coord[0], e->line_lim[0], e->color);
		e->line_lim[0]++;
	}
}
