/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:44:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:59 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned		i;
	unsigned char	*s1_ch;
	unsigned char	*s2_ch;

	s1_ch = (unsigned char*)s1;
	s2_ch = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	i = 0;
	while ((s1_ch[i] || s2_ch[i]) && i < n)
	{
		if (s1_ch[i] != s2_ch[i])
			return (s1_ch[i] - s2_ch[i]);
		i++;
	}
	return (0);
}
