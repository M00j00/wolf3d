/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:05:22 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 19:30:56 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if ((dest = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)) == NULL)
		return (NULL);
	dest = (char*)ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}
