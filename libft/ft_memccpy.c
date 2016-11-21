/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:24:36 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 17:31:18 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *cdest;
	unsigned char *csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	while (n--)
	{
		if ((*cdest++ = *csrc++) == (unsigned char)c)
			return ((void*)cdest);
	}
	return (NULL);
}
