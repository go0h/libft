/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:43:41 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 19:34:16 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10);
	}
	if (n < 0 && n > -10)
		ft_putchar('-');
	ft_putchar(((n % 10) < 0 ? -(n % 10) : (n % 10)) + '0');
}