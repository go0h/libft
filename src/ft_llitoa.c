/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:47:16 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/25 11:47:48 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_llitoa(long long int n)
{
	char	*ar;
	size_t	len;

	len = ft_int_len(n);
	if (n < 0)
		len += 1;
	ar = ft_strnew(len);
	--len;
	if (!ar)
		return (NULL);
	if (n < 0)
		ar[0] = '-';
	while (n / 10 != 0)
	{
		ar[len] = ((n % 10) < 0 ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
		--len;
	}
	ar[len] = (n < 0 ? -(n) : n) + '0';
	return (ar);
}
