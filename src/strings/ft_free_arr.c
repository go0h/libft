/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:41:37 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 15:05:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

void		ft_free_arr(char **s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_memset(&s[i], 0, ft_strlen(s[i]));
			free(s[i]);
			i++;
		}
		ft_memset(s, 0, i);
		free(s);
	}
	s = NULL;
}
