/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:17:23 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/07 16:19:43 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *csrc;

	csrc = (unsigned char*)src;
	while (n--)
	{
		if (*csrc == (unsigned char)c)
			return ((void*)csrc);
		csrc++;
	}
	return (NULL);
}
