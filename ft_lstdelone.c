/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:14 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 16:37:17 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *dell;

	if (alst != NULL)
	{
		dell = *alst;
		if (dell != NULL)
		{
			del(dell->content, dell->content_size);
			dell->next = NULL;
			free(*alst);
			*alst = NULL;
		}
		alst = NULL;
	}
}
