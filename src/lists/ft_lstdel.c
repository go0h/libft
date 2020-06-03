/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:23:56 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:33:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *next;

	if (alst && del)
	{
		temp = *alst;
		while (temp != NULL)
		{
			del(temp->content, temp->content_size);
			next = temp->next;
			temp->next = NULL;
			free(temp);
			temp = next;
		}
		*alst = NULL;
	}
}
