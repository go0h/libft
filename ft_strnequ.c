/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:40:18 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 16:40:37 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*s1u;
	unsigned char	*s2u;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	s1u = (unsigned char*)s1;
	s2u = (unsigned char*)s2;
	i = 0;
	while (i < n && (s1u[i] || s2u[i]))
	{
		if (s1u[i] != s2u[i])
			return (0);
		++i;
	}
	return (1);
}
