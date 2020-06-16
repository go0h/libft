/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 21:39:29 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/16 16:18:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARRAY_H
# define FT_DARRAY_H

# include "ft_memory.h"

/*
** DYNAMIC ARRAY
** ONLY FOR BASIC TYPES
**
**	size		- number of elements, stored in array
**	capacity	- max of elements, can be stored in array
**				without realloc memory
**	type_size	- size type, strored in array in BYTES
*/

typedef struct	s_darr
{
	size_t			size;
	size_t			capacity;
	size_t			type_size;
	char			*array;
}				t_darr;

/*
**	NEW_DYNAMIC ARRAY
**	Сreate a new array, and reserve capacity elements
**	type_size in BYTES.
**	Example: ft_da_new(10, sizeof(int)) create array with:
**	size = 0;
**	capacity = 10;
**	type_size = sizeof(int)
*/

t_darr			*ft_da_new(size_t capacity, size_t type_size);

/*
**	FREE AND ZEROED DYNAMIC ARRAY
*/

void			ft_da_delete(t_darr **arr);

/*
**	Delete element at the index
**	change size = size - 1
*/

void			ft_da_del_index(t_darr *arr, size_t index);

/*
**	Store to data last element and delete it
**	change size = size - 1
**	On error return 0
*/

int				ft_da_pop_last(t_darr *arr, void *data);

/*
**	Store to data element at the index
**	On error return 0
*/

int				ft_da_get_value(t_darr *arr, size_t index, void *data);

/*
**	Return pointer to element at the index
**	On error return NULL
*/

void			*ft_da_get_pointer(t_darr *arr, size_t index);

/*
**	Set the value to element at index
**	On error return 0
*/

int				ft_da_set(t_darr *arr, size_t index, void *value);

/*
**	Add element to the end of array
**	On error return NULL
*/

t_darr			*ft_da_add(t_darr *arr, void *value);

/*
**	Create deep copy of array
**	On error return NULL
*/

t_darr			*ft_da_copy(t_darr *src);

/*
**	Compate two dynamic arrays with cmp function
**	CMP function return 0 if two elements is equal
**	On succes return 0
*/

int				ft_da_cmp(t_darr *a1, t_darr *a2, int (*cmp)(void*, void*));

/*
**	Change each elemet in array with F function
*/

void			ft_da_iter(t_darr *arr, void (*f)(void*));

/*
**	Iterates a array and applies the function F to each element
**	to create a “fresh” list (using malloc(3))
**	resulting from the successive applications off.
**	If the allocation fails, the function returns NULL
*/

t_darr			*ft_da_map(t_darr *arr, int (*f)(void*, void*));

/*
**	Reduce capacity of array to fit it's size.
*/

t_darr			*ft_da_shrink(t_darr *arr);

/*
**	Sort array with quick sort algorithm, where:
**		LESS - checks whether LHS is less than RHS.
*/

void			ft_da_sort(t_darr *arr, int (*less)(void *, void *));

/*
**	Returns 1 if the array is sorted into order, dependent on CMP
*/

int				ft_da_issorted(t_darr *arr, int (*cmp)(void *, void*));

#endif
