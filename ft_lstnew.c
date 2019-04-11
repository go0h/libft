/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:01:17 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 17:12:22 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newl;

	if ((newl = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		newl->content = (void*)content;
		newl->content_size = content_size;
	}
	else
	{
		newl->content = NULL;
		newl->content_size = 0;
	}
	newl->next = NULL;
	return (newl);
}
