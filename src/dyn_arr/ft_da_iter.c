/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_da_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:04:51 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/04 17:02:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "stdio.h"

int			ft_da_cmp(t_darr *a1, t_darr *a2, int (*cmp)(void*, void*))
{
	size_t	i;

	if (!a1 || !a2 || !cmp)
		return (0);
	if (a1->size != a2->size || a1->type_size != a2->type_size)
		return (0);
	i = 0;
	while (i < a1->size)
	{
		if (cmp(&a1->array[i * a1->type_size], &a2->array[i * a2->type_size]))
			return (1);
		++i;
	}
	return (0);
}

void		ft_da_iter(t_darr *arr, void (*f)(void*))
{
	size_t i;

	if (!arr || !f)
		return ;
	i = 0;
	while (i < arr->size)
	{
		f(&arr->array[i * arr->type_size]);
		++i;
	}
}

t_darr		*ft_da_map(t_darr *arr, int (*f)(void*, void*))
{
	size_t	i;
	t_darr	*new_arr;

	if (!arr || !f)
		return (NULL);
	if (!(new_arr = ft_da_new(arr->size, arr->type_size)))
		return (NULL);
	i = 0;
	while (i < arr->size)
	{
		if (f(&arr->array[i * arr->type_size],\
			&new_arr->array[i * arr->type_size]))
		{
			ft_da_delete(&new_arr);
			return (NULL);
		}
		++i;
	}
	new_arr->size = arr->size;
	return (new_arr);
}
