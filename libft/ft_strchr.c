/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:19:36 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 20:09:24 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	if (*(src + ft_strlen(src)) == (char)c)
		return ((char*)src + ft_strlen(src));
	return ((char*)ft_memchr(src, c, ft_strlen(src)));
}
