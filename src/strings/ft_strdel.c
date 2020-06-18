/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:48:40 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 15:47:23 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		ft_memset(*as, 0, ft_strlen(*as));
		free(*as);
		*as = NULL;
	}
	as = NULL;
}
