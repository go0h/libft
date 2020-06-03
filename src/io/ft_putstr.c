/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:41:01 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:44:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"

int	ft_putstr(char const *str)
{
	if (str && *str)
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	return (0);
}
