/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:14 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:33:05 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && del)
	{
		temp = *alst;
		if (temp)
		{
			del(temp->content, temp->content_size);
			temp->next = NULL;
			free(*alst);
			*alst = NULL;
		}
		alst = NULL;
	}
}
