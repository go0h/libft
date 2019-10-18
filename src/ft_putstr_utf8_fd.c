/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utf8_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:15:25 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/12 13:43:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_utf8_fd(int const *str, int fd)
{
	int i;

	i = 0;
	while (*str)
	{
		i += ft_putchar_utf8_fd(*str, fd);
		++str;
	}
	return (i);
}
