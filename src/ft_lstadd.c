/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:57:32 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 18:08:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *temp;

	if (alst && *alst && new)
	{
		temp = *alst;
		new->next = temp;
		*alst = new;
	}
	else if (new)
	{
		temp = NULL;
		new->next = temp;
		*alst = new;
	}
}
