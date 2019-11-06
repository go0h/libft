/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:06:37 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/14 10:40:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*read_from_file_to_var(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*text;
	int		n;

	if (!(text = ft_strnew(0)))
		return (NULL);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (!(text = ft_strjoin_f(text, buf)))
			return (NULL);
	}
	if (!text[0])
	{
		free(text);
		return (NULL);
	}
	return (text);
}
