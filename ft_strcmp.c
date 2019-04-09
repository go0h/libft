/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:44:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:16 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_ch;
	unsigned char	*s2_ch;
	unsigned int	i;

	s1_ch = (unsigned char*)s1;
	s2_ch = (unsigned char*)s2;
	i = 0;
	while (s1_ch[i] || s2_ch[i])
	{
		if (s1_ch[i] != s2_ch[i])
			break ;
		++i;
	}
	return (s1_ch[i] - s2_ch[i]);
}
