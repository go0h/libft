/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:28:31 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 15:30:49 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *)s + ft_strlen(s));
	return (ft_memchr(s, c, ft_strlen(s)));
}
