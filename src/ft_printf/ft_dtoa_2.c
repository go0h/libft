/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 22:14:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/11/06 23:53:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_strlen_after_point(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '.' && str[i])
		++i;
	if (!str[i])
		return (-1);
	return (i + 1);
}

static int		ft_genzeros(char **str, int precision, char dot)
{
	char		*zeros;
	char		*temp;

	if (precision < 0)
		return (ft_strlen(*str));
	if (!(zeros = ft_strnew(precision + dot)))
		exit(MALLOC_FAILURE);
	ft_memset((void*)zeros, '0', precision + dot);
	dot ? zeros[0] = '.' : 0;
	temp = *str;
	*str = ft_strjoin_f(temp, zeros);
	free(zeros);
	return (ft_strlen(*str));
}

static int		check_round(char *str)
{
	int			i;

	i = 0;
	if ((str[i] != '.' && str[i] < '5') || (str[i] == '.' && str[i + 1] < '5'))
	{
		str[i] = '\0';
		return (0);
	}
	str[i] = '\0';
	while (str[++i] != '\0')
	{
		if (str[i] > '0')
			return (1);
	}
	return (0);
}

static void		round_ten(char *str)
{
	int			i;

	i = 0;
	if ((str[i] == '0' && str[i + 1] != '.' && str[i + 1]) || str[i] == ':')
	{
		str[i++] = '1';
		while (str[i] != '\0')
		{
			if (str[i] == '.')
			{
				str[i++] = '0';
				str[i++] = '.';
			}
			else
				str[i++] = '0';
		}
		str[i++] = '0';
		str[i] = '\0';
	}
}

int				ft_round_dbl(char **str, int precision)
{
	int			i;
	char		*dbl;

	dbl = *str;
	if ((i = ft_strlen_after_point(dbl)) == -1)
		return (ft_genzeros(str, precision, 1));
	precision < 0 ? *dbl += check_round(&dbl[i - 1]) : 0;
	round_ten(dbl);
	while (precision-- && dbl[++i])
		;
	if (!dbl[i])
		return (ft_genzeros(str, precision, 0));
	dbl[i - 1] += check_round(&dbl[i]);
	while (i > 0)
	{
		if (dbl[i] == ':')
		{
			dbl[i] = '0';
			dbl[i - 1] == '.' ? --i : 0;
			dbl[i - 1] += 1;
		}
		--i;
	}
	round_ten(dbl);
	return (ft_strlen(dbl));
}
