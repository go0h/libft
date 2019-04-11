/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:50:30 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 16:50:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_strnew(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s1, len1);
	ft_strncpy(&str[len1], s2, len2);
	return (str);
}
