/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:23:32 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 19:16:48 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *temp;

	if (lst && f)
	{
		if (!(begin = f(lst)))
			return (NULL);
		temp = begin;
		lst = lst->next;
		while (lst != NULL)
		{
			temp->next = f(lst);
			if (!temp->next)
			{
				ft_lstdel(&begin, &ft_del_mem);
				return (NULL);
			}
			temp = temp->next;
			lst = lst->next;
		}
		return (begin);
	}
	return (NULL);
}
