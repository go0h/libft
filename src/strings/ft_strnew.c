/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:42:56 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 21:08:19 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)(0 - 1))
		return (NULL);
	if (!(str = ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (str);
}
