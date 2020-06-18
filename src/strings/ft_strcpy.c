/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:27 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 15:45:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = ft_strlen(src);
	ft_memcpy(dest, src, i);
	dest[i] = '\0';
	return (dest);
}
