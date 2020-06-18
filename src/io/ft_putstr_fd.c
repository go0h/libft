/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:45:38 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:50:49 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"

int	ft_putstr_fd(char const *str, int fd)
{
	size_t	len;

	if (str && *str)
	{
		len = ft_strlen(str);
		write(fd, str, len);
		return (len);
	}
	return (0);
}
