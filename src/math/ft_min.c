/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:32:02 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/11 22:31:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ft_min(int a, int b)
{
	return (a > b ? b : a);
}

size_t	ft_mins(size_t a, size_t b)
{
	return (a > b ? b : a);
}
