/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:40:16 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/12 18:20:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*memes;
	size_t	i;

	if (size == 0)
		return (NULL);
	memes = (char*)malloc(size);
	if (memes == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		memes[i] = 0;
		++i;
	}
	return ((void*)memes);
}
