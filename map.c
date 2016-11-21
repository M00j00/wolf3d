/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:56:17 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/21 17:02:17 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_map(t_env *e)
{
	int			x;
	int			y;
	int			tex;

	tex = 0;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x % 3 && y % 3 && tex % 5)
				e->map[y][x] = 2;
			//else if (x == 3 && y == 5)
			//	e->map[y][x] = 2;
			//else if (x == 8 && y == 8)
			//	e->map[y][x] = 2;
			//else if (x == 4 && y == 9)
			//	e->map[y][x] = 2;
			else
				e->map[x][y] = 0;
			if (x == SPAWN || y == SPAWN || x == SPAWN + 1 || y == SPAWN + 1 ||
					x == SPAWN - 1 || y == SPAWN - 1)
				e->map[x][y] = 0;
			if (x == MAP_SIZE - 1 || x == 0 || y == MAP_SIZE - 1 || y == 0)
				e->map[x][y] = 1;
			x++;
			tex++;
		}
		y++;
	}
}

void		print_map(t_env *e)
{
	int			x;
	int			y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == (int)e->pos[0] && y == (int)e->pos[1])
				ft_putchar('x');
			else
				ft_putnbr(e->map[x][y]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putstr("\n\n\n");
}

void		print_mini_map(t_env *e)
{
	int		x;
	int		y;

	x = e->pos[0] - 10;
	while (x < e->pos[0] + 10)
	{
		y = e->pos[1] - 10;
		while (y < e->pos[1] +10)
		{
			if (x < MAP_SIZE && x > 0 && y < MAP_SIZE && y > 0)
				e->map[x][y] > 0 ? mlx_string_put(e->mlx, e->wnd,
						100 + x * 3, 100 + y * 3, 0x000000, " ") :
					mlx_string_put(e->mlx, e->wnd, (100 + x) * 3, (100 + y) * 3,
							0xFFFFFF, "W");
			y++;
		}
		x++;
	}
}
