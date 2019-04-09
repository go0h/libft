/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:48:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 18:52:23 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	char *str;
	
	str = *as;
	if (as != NULL)
	{
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		as = NULL;
	}
}
