/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:26:34 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 19:02:41 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_checkstr(const char *s)
{
	int		count;

	count = 0;
	while (!ft_isdigit(*s))
	{
		if (*s != '-' && *s != '+' && !ft_isspace(*s))
			return (0);
		if (count > 1)
			return (0);
		if (*s == '-' || *s == '+')
			count++;
		s++;
	}
	return (1);
}

static	int		ft_handlesign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static	char	*ft_lead_trim(const char *s)
{
	char	*str;

	str = (char*)s;
	while ((!ft_isdigit(*str) && (*str != '-' && *str != '+')) || *str == 0)
		str++;
	return (str);
}

int				ft_atoi(const char *s)
{
	int		res;
	int		sign;
	char	*str;

	res = 0;
	if (!ft_checkstr(s))
		return (res);
	str = ft_lead_trim(s);
	if ((sign = ft_handlesign(*str)))
		str++;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	if (sign)
		res *= sign;
	return (res);
}
