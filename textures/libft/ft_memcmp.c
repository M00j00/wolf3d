/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:19:17 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/07 16:22:11 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n--)
	{
		if (*c1 != *c2)
			return ((int)(*c1 - *c2));
		c1++;
		c2++;
	}
	return (0);
}
