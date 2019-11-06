/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:37:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/02 14:42:15 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	str = ft_strnew(len1 + len2);
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, len1);
	ft_strncpy(&str[len1], s2, len2);
	free((void*)s2);
	return (str);
}
