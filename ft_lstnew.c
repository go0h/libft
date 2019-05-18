/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:01:17 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/02 10:47:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newl;

	if (!(newl = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size)
	{
		if (!(newl->content = (void*)ft_memalloc(content_size)))
		{
			free(newl);
			return (NULL);
		}
		ft_memcpy(newl->content, content, content_size);
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
