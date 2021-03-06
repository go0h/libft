/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:57:32 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/16 22:18:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	ft_lst_push_back(t_list **begin, t_list *new)
{
	t_list	*temp;

	if (!begin)
		return ;
	if (!*begin)
		*begin = new;
	else
	{
		temp = *begin;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
