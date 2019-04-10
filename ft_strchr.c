/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:28:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 19:29:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_ch;
	unsigned char	*s_ch;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	c_ch = (unsigned char)c;
	s_ch = (unsigned char*)s;
	while (s_ch[i])
	{
		if (s_ch[i] == c_ch)
			return ((char*)&s_ch[i]);
		i++;
	}
	if (s_ch[i] == c_ch)
		return ((char*)&s_ch[i]);
	else
		return (NULL);
}