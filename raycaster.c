/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:56:39 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/21 14:54:50 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			calc_dist_and_step(t_env *e)
{
	if (e->ray_dir[0] < 0)
	{
		e->step[0] = -1;
		e->side_dist[0] = (e->ray_pos[0] - e->map_coord[0]) * e->delta_dist[0];
	}
	else
	{
		e->step[0] = 1;
		e->side_dist[0] = (e->map_coord[0] + 1.0 - e->ray_pos[0])
			* e->delta_dist[0];
	}
	if (e->ray_dir[1] < 0)
	{
		e->step[1] = -1;
		e->side_dist[1] = (e->ray_pos[1] - e->map_coord[1]) * e->delta_dist[1];
	}
	else
	{
		e->step[1] = 1;
		e->side_dist[1] = (e->map_coord[1] + 1.0 - e->ray_pos[1])
			* e->delta_dist[1];
	}
}

static void			init_ray(t_env *e, int x)
{
	e->cam_pos = 2 * x / (double)WIN_W - 1;
	e->ray_pos[0] = e->pos[0];
	e->ray_pos[1] = e->pos[1];
	e->ray_dir[0] = e->dir[0] + e->plan[0] * e->cam_pos;
	e->ray_dir[1] = e->dir[1] + e->plan[1] * e->cam_pos;
	e->map_coord[0] = (int)e->ray_pos[0];
	e->map_coord[1] = (int)e->ray_pos[1];
	e->delta_dist[0] = sqrt(1 + (e->ray_dir[1] * e->ray_dir[1])
			/ (e->ray_dir[0] * e->ray_dir[0]));
	e->delta_dist[1] = sqrt(1 + (e->ray_dir[0] * e->ray_dir[0])
			/ (e->ray_dir[1] * e->ray_dir[1]));
	e->colision = 0;
	calc_dist_and_step(e);
}

static void			get_dist(t_env *e)
{
	if (e->side == 0 || e->side == 1)
		e->perp_dist = (e->map_coord[0] - e->ray_pos[0] + (1 - e->step[0])
				/ 2) / e->ray_dir[0];
	else
		e->perp_dist = (e->map_coord[1] - e->ray_pos[1] + (1 - e->step[1])
				/ 2) / e->ray_dir[1];
}

void				cast_ray(t_env *e, int x)
{
	init_ray(e, x);
	while (e->colision == 0)
	{
		if (e->side_dist[0] < e->side_dist[1])
		{
			e->side_dist[0] += e->delta_dist[0];
			e->map_coord[0] += e->step[0];
			e->side = (e->ray_dir[0] < 0) ? 0 : 1;
		}
		else
		{
			e->side_dist[1] += e->delta_dist[1];
			e->map_coord[1] += e->step[1];
			e->side = (e->ray_dir[1] < 0) ? 2 : 3;
		}
		if (e->map[e->map_coord[0]][e->map_coord[1]] > 0)
			e->colision = 1;
	}
	get_dist(e);
}
