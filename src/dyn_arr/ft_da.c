/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_da.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:00:53 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/04 17:36:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

t_darr		*ft_da_new(size_t capacity, size_t type_size)
{
	t_darr	*arr;

	if (!(arr = (t_darr*)malloc(sizeof(t_darr))))
		return (NULL);
	ft_bzero(arr, sizeof(t_darr));
	arr->type_size = type_size;
	if (!capacity)
		return (arr);
	arr->capacity = capacity;
	if (!(arr->array = (char*)malloc(type_size * capacity)))
	{
		free(arr);
		return (NULL);
	}
	ft_bzero(arr->array, type_size * capacity);
	return (arr);
}

void		ft_da_delete(t_darr **arr)
{
	if (!arr)
		return ;
	if (*arr)
	{
		if ((*arr)->capacity)
			ft_bzero((*arr)->array, (*arr)->type_size * (*arr)->capacity);
		free((*arr)->array);
		ft_bzero((*arr), sizeof(t_darr));
		free((*arr));
		arr = NULL;
	}
}

void		ft_da_del_index(t_darr *arr, size_t index)
{
	size_t pos;

	if (index >= arr->size)
		return ;
	arr->size = arr->size - 1;
	pos = index * arr->type_size;
	ft_memcpy(&arr->array[pos], &arr->array[pos + arr->type_size],\
		arr->type_size * (arr->size - index));
}

t_darr		*ft_da_copy(t_darr *src)
{
	t_darr		*copy;

	if (!(copy = ft_da_new(src->size, src->type_size)))
		return (NULL);
	copy->size = src->size;
	ft_memcpy(copy->array, src->array, src->type_size * copy->size);
	return (copy);
}

t_darr		*ft_da_shrink(t_darr *arr)
{
	char	*new_arr;

	if (arr->size == arr->capacity)
		return (arr);
	if (!(new_arr = (char*)malloc(arr->size * arr->type_size)))
		return (NULL);
	ft_memcpy(new_arr, arr->array, arr->size * arr->type_size);
	ft_bzero(arr->array, arr->capacity * arr->type_size);
	free(arr->array);
	arr->array = new_arr;
	arr->capacity = arr->size;
	return (arr);
}
