/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:58 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 21:13:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || len == (size_t)(0 - 1))
		return (NULL);
	if (!(sub = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_memcpy(sub, &s[start], len));
}
