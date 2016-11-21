/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:34:31 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 17:25:43 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(int n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	len = ft_intlen(n);
	sign = (n < 0) ? 1 : 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	res = res + len + sign;
	*res = '\0';
	if (n == 0)
		*--res = '0';
	while (n != 0)
	{
		*--res = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (sign)
		*--res = '-';
	return (res);
}
