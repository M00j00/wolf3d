/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:45:43 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/12 17:29:14 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*next_node;
	t_list		*tmp;

	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		next_node = (*alst)->next;
		free(*alst);
		while (next_node != NULL)
		{
			del((next_node)->content, (next_node)->content_size);
			tmp = next_node;
			next_node = next_node->next;
			free(tmp);
		}
		*alst = NULL;
	}
	return ;
}
