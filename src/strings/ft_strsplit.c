/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:37:28 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:32:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

static size_t	ft_strlenc(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		++i;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	words;
	char	**arr;

	words = ft_count_words(s, c);
	if (!s || !(arr = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s == c)
			++s;
		len = ft_strlenc(s, c);
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
