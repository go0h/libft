/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_utf8_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:43:50 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:17:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int	ft_putnstr_utf8_fd(int const *str, int fd, int len)
{
	int i;

	i = 0;
	len -= ft_lenwchar(*str);
	while (*str && len >= 0)
	{
		i += ft_putchar_utf8_fd(*str, fd);
		++str;
		len -= ft_lenwchar(*str);
	}
	return (i);
}
