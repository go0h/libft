/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:12:20 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 20:12:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isalnum(int c)
{
	unsigned char c_ch;

	c_ch = (unsigned char)c;
	if ((c_ch > 64 && c_ch < 91) || (c_ch > 96 && c_ch < 123)\
			|| (c_ch > 47 && c_ch < 58))
		return (1);
	else
		return (0);
}