/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:22:52 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 19:37:31 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstend;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dstend = i;
	while (src[i - dstend] && i < size - 1)
	{
		dst[i] = src[i - dstend];
		i++;
	}
	if (dstend < size)
		dst[i] = '\0';
	return ((size_t)(dstend + ft_strlen(src)));
}
