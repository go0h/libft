/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:12:15 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/18 13:41:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_utf8(int c)
{
	if (c < 2048)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c < 65536)
	{
		ft_putchar((c >> 12 & 0x3F) + 0xE0);
		ft_putchar((c >> 6 & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c < 1114112)
	{
		ft_putchar((c >> 18 & 0x3F) + 0xF0);
		ft_putchar((c >> 12 & 0x3F) + 0x80);
		ft_putchar((c >> 6 & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}
