/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:46:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/06 10:27:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			negative(const char *str, int i);

static int			tabs(const char *str);

int					ft_atoi(const char *str)
{
	int			i;
	int			nb;
	int			flag;

	nb = 0;
	i = tabs(str);
	flag = negative(str, i);
	if (flag == 1 || flag == -1)
		++i;
	while (str[i] != '\0')
	{
		if (str[i] > 47 && str[i] < 58)
		{
			nb += str[i] - 48;
			if (str[i + 1] > 47 && str[i + 1] < 58)
				nb *= 10;
		}
		else
			break ;
		++i;
	}
	if (flag == -1)
		nb *= flag;
	return (nb);
}

static int			negative(const char *str, int i)
{
	if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
		return (-1);
	else if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
		return (1);
	return (0);
}

static int			tabs(const char *str)
{
	int i;

	i = 0;
	while (str[i] > 8 & str[i] < 14 || str[i] == 32)
		++i;
	return (i);
}
