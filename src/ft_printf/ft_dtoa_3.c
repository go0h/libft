/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:51:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/18 14:48:53 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_isspecdouble(t_ex_double dbl)
{
	char		*str;

	str = NULL;
	if (!(dbl.t_fd.exponent ^ 0x7FFF) && (dbl.t_fd.mantissa & (3L << 61)))
	{
		if (!(str = ft_strdup("nan")))
			exit(MALLOC_FAILURE);
	}
	else if (!(dbl.t_fd.exponent ^ 0x7FFF) && (dbl.t_fd.mantissa & (1L << 63)))
	{
		if (!(str = ft_strdup(dbl.t_fd.sign ? "-inf" : "inf")))
			exit(MALLOC_FAILURE);
	}
	return (str);
}
