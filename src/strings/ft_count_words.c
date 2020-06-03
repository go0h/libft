/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:22:50 by pcredibl          #+#    #+#             */
/*   Updated: 2020/06/02 18:58:09 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_count_words(char const *s, char c)
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
