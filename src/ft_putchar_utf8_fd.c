/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:12:15 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/18 13:45:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_utf8_fd(int c, int fd)
{
	if (c < 2048)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c < 65536)
	{
		ft_putchar_fd((c >> 12 & 0x3F) + 0xE0, fd);
		ft_putchar_fd((c >> 6 & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c < 1114112)
	{
		ft_putchar_fd((c >> 18 & 0x3F) + 0xF0, fd);
		ft_putchar_fd((c >> 12 & 0x3F) + 0x80, fd);
		ft_putchar_fd((c >> 6 & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
}
