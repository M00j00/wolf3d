/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:21:23 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/15 16:13:12 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t nlen;

	if ((nlen = ft_strlen(needle)) == 0)
		return ((char*)haystack);
	while (*haystack && ft_strlen(haystack) >= nlen)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, nlen))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
