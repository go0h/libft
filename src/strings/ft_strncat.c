/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:55:15 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:47:02 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	n = len2 > n ? n : len2;
	ft_memcpy(&s1[len1], s2, n);
	s1[len1 + n] = 0;
	return (s1);
}
