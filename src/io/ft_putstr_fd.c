/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:45:38 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:44:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"

int	ft_putstr_fd(char const *str, int fd)
{
	if (str && *str)
	{
		write(fd, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	return (0);
}
