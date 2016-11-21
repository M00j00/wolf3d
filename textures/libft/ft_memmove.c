/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:15:09 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 18:28:11 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	if (cdest > csrc)
	{
		cdest += n;
		csrc += n;
		while (n--)
			*--cdest = *--csrc;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
