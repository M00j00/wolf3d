/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:56:38 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/15 17:22:58 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *src)
{
	const char	*end;
	char		*res;

	if (!src)
		return (NULL);
	while (ft_isspace(*src))
		src++;
	end = src + ft_strlen(src) - 1;
	while (end > src && ft_isspace(*end))
		end--;
	end++;
	if (!(res = (char*)malloc(sizeof(char) * (end - src + 1))))
		return (NULL);
	res = ft_memcpy(res, src, (end - src));
	res[(end - src)] = '\0';
	return (res);
}
