/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:08:29 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/01 16:34:58 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	ret = (char*)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
