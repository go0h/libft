/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_sp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:58 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/16 16:44:05 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s)
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
		if (ft_isspace(s[i]) && flag == 0)
			flag = 1;
		else if (!ft_isspace(s[i]) && flag == 1)
		{
			++count;
			flag = 0;
		}
		++s;
	}
	return (count);
}

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
	size_t	words;
	size_t	len;
	char	**arr;

	words = ft_count_words(s);
	if (!s || (arr = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	i = 0;
	while (words--)
	{
		while (ft_isspace(*s))
			++s;
		len = ft_strlen_sp(s);
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
