/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:22:50 by pcredibl          #+#    #+#             */
/*   Updated: 2019/04/24 12:41:16 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(char const *str, char c)
{
	size_t	wc;
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	wc = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i] != '\0' && str[i - 1] == c)
				|| (str[i] != c && i == 0))
			wc++;
		i++;
	}
	return (wc);
}
