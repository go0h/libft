/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_da_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:45:00 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/09 20:11:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

static void		ft_da_swap(t_darr *arr, char *p, char *q)
{
	size_t	i;
	char	temp;

	i = 0;
	while (i++ < arr->type_size)
	{
		temp = *p;
		*p++ = *q;
		*q++ = temp;
	}
}

size_t			partition(t_darr *arr, int s, int e, int (*less)(void *, void*))
{
	char	*p1;
	char	*p2;
	char	*store;
	int		index;

	if (s >= e)
		return (0);
	p1 = ft_da_get_pointer(arr, s);
	p2 = ft_da_get_pointer(arr, e);
	ft_da_swap(arr, ft_da_get_pointer(arr, (s + e) / 2), p2);
	store = p1;
	index = s;
	while (p1 != p2)
	{
		if (less(p1, p2))
		{
			ft_da_swap(arr, p1, store);
			store = store + arr->type_size;
			++index;
		}
		p1 = p1 + arr->type_size;
	}
	ft_da_swap(arr, store, p2);
	return (index);
}

static void		ft_qsort(t_darr *arr, int s, int e, int (*less)(void *, void*))
{
	int		part_index;

	if (s >= e)
		return ;
	part_index = partition(arr, s, e, less);
	ft_qsort(arr, s, part_index, less);
	ft_qsort(arr, part_index + 1, e, less);
}

void			ft_da_sort(t_darr *arr, int (*less)(void *, void *))
{
	ft_qsort(arr, 0, arr->size - 1, less);
}

int				ft_da_issorted(t_darr *arr, int (*cmp)(void *, void*))
{
	size_t	i;

	i = 0;
	while (i < arr->size - 1)
	{
		if (!cmp(ft_da_get_pointer(arr, i), ft_da_get_pointer(arr, i + 1)))
			return (0);
		++i;
	}
	return (1);
}
