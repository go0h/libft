/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:06:18 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 20:27:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					m;
	size_t				i;
	const unsigned char	*s1_ch;
	const unsigned char	*s2_ch;

	s1_ch = (const unsigned char*)s1;
	s2_ch = (const unsigned char*)s2;
	i = 0;
	m = 0;
	while (i < n)
	{
		if (s1_ch[i] != s2_ch[i])
		{
			m = (int)(s1_ch[i] - s2_ch[i]);
			return (m);
		}
		++i;
	}
	return (m);
}
