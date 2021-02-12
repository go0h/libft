/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_ignore_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:49:31 by astripeb          #+#    #+#             */
/*   Updated: 2021/02/12 20:55:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_strcmp_ignore_case(const char *s1, const char *s2)
{
	char	*s1_ch;
	char	*s2_ch;

	s1_ch = (char*)s1;
	s2_ch = (char*)s2;
	while (*s1_ch && *s2_ch)
	{
		if (ft_tolower(*s1_ch) != ft_tolower(*s2_ch))
			return (ft_tolower(*s1_ch) - ft_tolower(*s2_ch));
		++s1_ch;
		++s2_ch;
	}
	return (ft_tolower(*s1_ch) - ft_tolower(*s2_ch));
}

