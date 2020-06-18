/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:47:04 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 15:49:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;

	i = ft_strlen(s1);
	if (!(dest = ft_strnew(i)))
		return (NULL);
	return (ft_strcpy(dest, s1));
}
