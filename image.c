/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:52:11 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/21 16:14:49 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			img_put_pixel(t_env *e, int x, int y, int color)
{
	int			byte;

	byte = y * e->img->line_size + (e->img->bpp * x / 8);
	if (y < WIN_H && x < WIN_W && y  > 0 && x > 0)
	{
		e->img->pxl[byte] = color;
		e->img->pxl[++byte] = (color / 256);
		e->img->pxl[++byte] = (color / 256 / 256);
	}
}

int				img_get_pixel(t_env *e, t_img *img, int x, int y)
{
	int			byte;
	int			color;
	int			r;
	int			g;
	int			b;

	byte = y * img->line_size + (img->bpp * x / 8);
	r = img->pxl[byte];
	g = img->pxl[++byte] * 256;
	b = img->pxl[++byte] * 256 * 256;
	color = r + g + b;
	return (color);
}

static void		calc_line_limits(t_env *e)
{
	e->line_h = (int) (WIN_H / e->perp_dist + 1);
	e->line_lim[0] = -e->line_h / 2 + WIN_H / 2;
	e->line_lim[1] = e->line_h / 2 + WIN_H / 2;
	if (e->line_lim[0] < 0)
		e->line_lim[0] = 0;
	if (e->line_lim[1] >= WIN_H)
		e->line_lim[1] = WIN_H - 1;
}

void			draw_view(t_env *e)
{
	e->screen_coord[0] = 0;
	while (e->screen_coord[0] < WIN_W)
	{
		cast_ray(e, e->screen_coord[0]);
		calc_line_limits(e);
		draw_texture(e);
		e->screen_coord[0]++;
	}
}

t_img		*new_img(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->ptr = mlx_new_image(e->mlx, width, height);
	img->pxl = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	return (img);
}
