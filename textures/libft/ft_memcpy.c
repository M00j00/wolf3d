/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:16:28 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 19:02:57 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned char		*csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	while (n--)
	{
		*cdest++ = *csrc++;
	}
	return (dest);
}
