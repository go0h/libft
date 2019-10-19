/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:06:40 by pcredibl          #+#    #+#             */
/*   Updated: 2019/04/22 22:14:32 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	page_del(t_list **lst)
{
	t_list	*temp;

	if (*lst != NULL)
	{
		temp = *lst;
		while (temp != NULL)
		{
			temp = *lst;
			free(*lst);
			(*lst)->next = NULL;
			*lst = temp->next;
		}
	}
}
