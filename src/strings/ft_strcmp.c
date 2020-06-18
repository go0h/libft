/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:44:08 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 15:37:24 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_ch;
	unsigned char	*s2_ch;

	s1_ch = (unsigned char*)s1;
	s2_ch = (unsigned char*)s2;
	while (*s1_ch && *s2_ch)
	{
		if (*s1_ch++ != *s2_ch++)
			return (*--s1_ch - *--s2_ch);
	}
	return (*s1_ch - *s2_ch);
}
