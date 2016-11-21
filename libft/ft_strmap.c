/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:33:52 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/03 16:25:13 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ret;

	ret = NULL;
	if (s && f)
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str)
		{
			ret = str;
			while (*s != '\0')
				*str++ = f(*s++);
			*str = '\0';
		}
	}
	return (ret);
}
