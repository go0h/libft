/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:08:40 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:33:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *temp;
	t_list *next;

	if (lst && f)
	{
		temp = lst;
		while (temp != NULL)
		{
			next = temp->next;
			f(temp);
			temp = next;
		}
	}
}
