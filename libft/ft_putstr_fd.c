/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:04:50 by amanchon          #+#    #+#             */
/*   Updated: 2016/02/10 19:16:41 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (!fd)
		return ;
	if (s)
		write(fd, s, ft_strlen(s));
	return ;
}
