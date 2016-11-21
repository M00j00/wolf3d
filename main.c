/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:02:46 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/21 16:53:33 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO
 *
 * fix les textures
 * add des mechants/objet (si color == noir ne pas display)
 * implementer les stats des personnages
 * add une arme/tirer
 *
 *CHASSE AU MALLOC ATTRAPEZ LES TOUS!!
 *
 */

#include "wolf3d.h"

int			destroy(t_env *e)
{
	exit(0);
}

void		spawn_player(t_env *e)
{
	e->dir[0] = 1;
	e->dir[1] = 0;
	e->plan[0] = 0.00;
	e->plan[1] = -0.50;
	e->movespd = 0.20;
	e->rotspd = 0.10;
	e->pos[0] = SPAWN;
	e->pos[1] = SPAWN;
	e->textswitch = 1;
	e->skybox_off = 0;
	print_map(e);
//	printf("cos60%f\tsin60%f\ttan60%f\n", cos(60), sin(60), tan(60));
//	exit(0);
}

t_env		*init_env()
{
	t_env		*e;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx = mlx_init()))
		return (NULL);
	if (!(e->wnd = mlx_new_window(e->mlx, WIN_W, WIN_H, "WOLF42D")))
		return (NULL);
	if (!(e->img = new_img(e, WIN_W, WIN_H)))
		return (NULL);
	init_map(e);
	spawn_player(e);
	init_texture(e);
	e->colors[0] = 0x05398c;
	e->colors[1] = 0x8c0519;
	e->colors[2] = 0x348c05;
	e->colors[3] = 0x8c7305;
	e->key_state[0] = 0;
	e->key_state[1] = 0;
	e->key_state[2] = 0;
	e->key_state[3] = 0;
	return (e);
}

int			main(void)
{
	t_env		*e;

	if (!(e = init_env()))
		return (1);
	//test_tex(e);
	mlx_loop_hook(e->mlx, refresh_window, e);
	mlx_hook(e->wnd, KEY_PRESS, KEY_PRESS_MASK, key_hook_press, e);
	mlx_hook(e->wnd, KEY_RELEASE, KEY_RELEASE_MASK, key_hook_release, e);
	mlx_hook(e->wnd, WIN_DESTROY, WIN_DESTROY_MASK, destroy, e);
	//mlx_key_hook(e->wnd, key_hook, e);
	mlx_expose_hook(e->wnd, refresh_window, e);
	//refresh_window(e);
	//wexit(e);
	mlx_loop(e->mlx);
	return (0);
}
