/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:06 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/18 11:09:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_search_n(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (i);
}

static int			ft_pre_str(char **data, char **line)
{
	size_t	i;
	size_t	n;
	char	*temp;

	if (!data || !*data)
		return (0);
	temp = *data;
	i = ft_search_n(temp);
	n = ft_strlen(temp);
	if (*temp == '\0')
		ft_strdel(data);
	else if ((*line = ft_strnew(i)))
	{
		ft_strncpy(*line, temp, i);
		*data = ft_strsub(temp, i + 1, n - i);
		free(temp);
		if (!*data)
			return (-1);
	}
	if (n - i >= 1)
		return (1);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				n;
	char			*temp;
	char			buf[BUFF_SIZE + 1];
	static char		*fds[12000];

	if (!line || fd < 0 || BUFF_SIZE < 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (!fds[fd] && !(fds[fd] = ft_strnew(0)))
			return (-1);
		if (!(temp = ft_strjoin(fds[fd], buf)))
			return (-1);
		free(fds[fd]);
		fds[fd] = temp;
		if ((int)ft_search_n(buf) < n && ft_pre_str(&fds[fd], line) == 1)
			return (1);
	}
	if (ft_pre_str(&fds[fd], line) == -1)
		return (-1);
	if (!fds[fd])
		return (0);
	return (1);
}
