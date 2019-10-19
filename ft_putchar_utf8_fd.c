/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utf8_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:30:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/12 16:07:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_utf8_fd(int c, int fd)
{
	char n;

	n = 1;
	if (c < 128)
		write(fd, &c, 1);
	else if (c < 2048)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		n += ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c < 65536)
	{
		ft_putchar_fd((c >> 12 & 0x3F) + 0xE0, fd);
		n += ft_putchar_fd((c >> 6 & 0x3F) + 0x80, fd);
		n += ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c < 1114112)
	{
		ft_putchar_fd((c >> 18 & 0x3F) + 0xF0, fd);
		n += ft_putchar_fd((c >> 12 & 0x3F) + 0x80, fd);
		n += ft_putchar_fd((c >> 6 & 0x3F) + 0x80, fd);
		n += ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	return (n);
}
