/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:06:50 by pcredibl          #+#    #+#             */
/*   Updated: 2019/06/14 18:50:17 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	count_print(long long int addr, int pr_count)
{
	int		*p_var;

	p_var = (int*)addr;
	*p_var = pr_count;
}
