/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:45:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/05 16:40:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *str, int fd)
{
	if (str && *str)
	{
		write(fd, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	return (0);
}
