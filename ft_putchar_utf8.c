/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:28:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/12 13:20:12 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_utf8(int c)
{
	char n;

	n = 1;
	if (c < 128)
		write(1, &c, 1);
	else if (c < 2048)
	{
		ft_putchar((c >> 6) + 0xC0);
		n += ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c < 65536)
	{
		ft_putchar((c >> 12 & 0x3F) + 0xE0);
		n += ft_putchar((c >> 6 & 0x3F) + 0x80);
		n += ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c < 1114112)
	{
		ft_putchar((c >> 18 & 0x3F) + 0xF0);
		n += ft_putchar((c >> 12 & 0x3F) + 0x80);
		n += ft_putchar((c >> 6 & 0x3F) + 0x80);
		n += ft_putchar((c & 0x3F) + 0x80);
	}
	return (n);
}
