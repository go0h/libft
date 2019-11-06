/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:44:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/08 17:00:33 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*laitoa(long int a[])
{
	short		i;
	short		j;
	int			k;
	char		*str;

	if ((i = size_long(a, MAX_LEN)) == -1)
		return (ft_strdup("0"));
	if (!(str = ft_strnew((i + 1) * BASE_LEN)))
		exit(MALLOC_FAILURE);
	k = BASE;
	while (a[i] / k == 0)
		k /= 10;
	j = 0;
	k *= 10;
	while (i >= 0)
	{
		while ((k /= 10) > 0)
			str[j++] = (a[i] / k % 10) + '0';
		--i;
		k = BASE;
	}
	return (str);
}

char	*laitoe(long int a[])
{
	short		i;
	short		j;
	int			k;
	char		*str;

	if ((i = size_long(a, MAX_LEN)) == -1)
		return (ft_strdup("0"));
	if (!(str = ft_strnew((i + 1) * BASE_LEN)))
		exit(MALLOC_FAILURE);
	k = BASE;
	while (a[i] / k == 0)
		k /= 10;
	j = 0;
	k *= 10;
	while (i >= 0)
	{
		while ((k /= 10) > 0)
		{
			j == 1 ? str[j++] = '.' : 0;
			str[j++] = (a[i] / k % 10) + '0';
		}
		--i;
		k = BASE;
	}
	return (str);
}
