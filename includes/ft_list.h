/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:28:08 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/16 22:22:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void			ft_lstadd(t_list **alst, t_list *new_list);

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_lst_push_back(t_list **begin, t_list *new);

t_list			*ft_lst_reverse(t_list *src);

#endif
