/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:42:46 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:38:41 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*trim;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	if ((j = ft_strlen(s)))
		j -= 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		--j;
	++j;
	if (i > j)
		trim = ft_strnew(0);
	else
	{
		trim = ft_strnew(j - i);
		if (!trim)
			return (NULL);
		trim = ft_strncpy(trim, &s[i], j - i);
	}
	return (trim);
}
