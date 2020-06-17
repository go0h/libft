/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:12:06 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/16 22:31:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lst_reverse(t_list *src)
{
	t_list	*dst;
	t_list	*temp;

	dst = NULL;
	while (src != NULL)
	{
		temp = src;
		src = src->next;
		temp->next = dst;
		dst = temp;
	}
	return (dst);
}
