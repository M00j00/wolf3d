/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:41:18 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/13 01:06:57 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_img(t_img *img){}
void		free_env(t_env *e)
{
	int		i;

	i = 0;
	free_img(e->img);
	ft_putendl("img");
	/*while (i < 8)
		free(&e->texture[i++]);
	*/ft_putendl("tex");
	if (e != NULL)
		free(e);
	ft_putendl("env");
}

void		wexit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->wnd);
	free_env(e);
	exit(1);

}
