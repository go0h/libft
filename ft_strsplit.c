/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:37:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/12 18:23:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t flag;
	size_t count;
	size_t i;

	i = 0;
	flag = 1;
	count = 0;
	if (!s)
		return (count);
	while (s[i] != '\0')
	{
		if (s[i] == c && flag == 0)
			flag = 1;
		else if (s[i] != c && flag == 1)
		{
			++count;
			flag = 0;
		}
		++s;
	}
	return (count);
}

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
	size_t	words;
	size_t	len;
	char	**arr;

	words = ft_count_words(s, c);
	if (!s || (arr = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s == c)
			++s;
		len = ft_strlenc(s, c);
		if ((arr[i] = ft_strsub(s, 0, len)) == NULL)
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
