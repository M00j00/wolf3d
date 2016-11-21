/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:19:49 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 19:48:52 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		i;

	i = ft_strlen(src);
	while (i >= 0)
	{
		if (src[i] == (char)c)
			return ((char*)(src + i));
		i--;
	}
	return (NULL);
}
