/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:20:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/06/20 22:06:28 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	eoc(const char *str)
{
	int		len;

	len = 0;
	while (*++str != '}' && *str)
		len++;
	return (len + 1);
}

int			set_color(const char *str, int *n, int fd)
{
	if (!ft_strncmp(str, "{black}", 7))
		ft_putstr_fd("\x1b[30m", fd);
	else if (!ft_strncmp(str, "{red}", 5))
		ft_putstr_fd("\x1b[31m", fd);
	else if (!ft_strncmp(str, "{green}", 7))
		ft_putstr_fd("\x1b[32m", fd);
	else if (!ft_strncmp(str, "{yellow}", 8))
		ft_putstr_fd("\x1b[33m", fd);
	else if (!ft_strncmp(str, "{darkblue}", 10))
		ft_putstr_fd("\x1b[34m", fd);
	else if (!ft_strncmp(str, "{purple}", 8))
		ft_putstr_fd("\x1b[35m", fd);
	else if (!ft_strncmp(str, "{blue}", 6))
		ft_putstr_fd("\x1b[36m", fd);
	else if (!ft_strncmp(str, "{eoc}", 5))
		ft_putstr_fd("\x1b[37m", fd);
	else
	{
		ft_putchar_fd('{', fd);
		*n += 1;
		return (0);
	}
	return (eoc(str));
}
