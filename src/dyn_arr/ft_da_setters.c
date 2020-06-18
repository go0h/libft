/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_da_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 22:06:45 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 13:41:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

int			ft_da_pop_last(t_darr *arr, void *data)
{
	if (!arr)
		return (0);
	arr->size = arr->size - 1;
	ft_memcpy(data, &arr->array[arr->size * arr->type_size], arr->type_size);
	return (1);
}

int			ft_da_get_value(t_darr *arr, size_t index, void *data)
{
	if (index >= arr->size)
		return (0);
	ft_memcpy(data, &arr->array[index * arr->type_size], arr->type_size);
	return (1);
}

void		*ft_da_get_pointer(t_darr *arr, size_t index)
{
	if (index >= arr->size)
		return (NULL);
	return (&(arr->array[index * arr->type_size]));
}

int			ft_da_set(t_darr *arr, size_t index, void *data)
{
	if (index >= arr->size)
		return (0);
	ft_memcpy(&arr->array[index * arr->type_size], data, arr->type_size);
	return (1);
}

t_darr		*ft_da_add(t_darr *arr, void *data)
{
	char *new_arr;

	if (arr->size < arr->capacity)
	{
		ft_memcpy(&arr->array[arr->size * arr->type_size],\
		data, arr->type_size);
		arr->size += 1;
		return (arr);
	}
	arr->capacity = !arr->capacity ? 1 : arr->capacity * 2;
	if (!(new_arr = (char*)malloc(arr->type_size * arr->capacity)))
	{
		ft_da_delete(&arr);
		return (NULL);
	}
	ft_memcpy(new_arr, arr->array, arr->size * arr->type_size);
	ft_memcpy(&new_arr[arr->size * arr->type_size], data, arr->type_size);
	ft_bzero(arr->array, arr->type_size * arr->size);
	arr->size = arr->size + 1;
	free(arr->array);
	arr->array = new_arr;
	return (arr);
}
