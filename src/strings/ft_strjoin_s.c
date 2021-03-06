/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:37:52 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 17:06:14 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin_s(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !(s1 = ft_strnew(0L)))
		return (NULL);
	if (!s2 && !(s2 = ft_strnew(0L)))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = ft_strnew(len1 + len2)))
		return (NULL);
	ft_strncpy(str, s1, len1);
	ft_strncpy(&str[len1], s2, len2);
	ft_strdel((char**)&s2);
	return (str);
}
