/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:44:31 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:10:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((*s1 || *s2) && n--)
	{
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	}
	return (0);
}
