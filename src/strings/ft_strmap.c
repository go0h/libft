/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:37:58 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 17:09:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(s[i]);
		++i;
	}
	return (str);
}
