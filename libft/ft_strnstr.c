/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:18:28 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/15 16:12:35 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		nlen;
	size_t		hlen;

	hlen = ft_strlen(haystack);
	if ((nlen = ft_strlen(needle)) == 0)
		return ((char*)haystack);
	while (n-- >= ft_strlen(needle) && *haystack != '\0')
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, nlen))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
