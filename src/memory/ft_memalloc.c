/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:40:16 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 13:38:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
