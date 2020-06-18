/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_sp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:58 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:33:00 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

static size_t	ft_strlen_sp(char const *s)
{
	size_t i;

	i = 0;
	while (!ft_isspace(s[i]) && s[i] != '\0')
		++i;
	return (i);
}

char			**ft_strsplit_sp(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	words;
	char	**arr;

	words = ft_count_words(s, ' ');
	if (!s || !(arr = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	while (words--)
	{
		while (ft_isspace(*s))
			++s;
		len = ft_strlen_sp(s);
		if (!(arr[i] = ft_strsub(s, 0, len)))
		{
			ft_free_arr(arr);
			return (NULL);
		}
		s += len;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
