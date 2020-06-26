/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:56:07 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/26 20:36:09 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <time.h>

# define FT_TYPE size_t

int	cmp_tree(void *d1, void *d2)
{
	FT_TYPE n1 = *(FT_TYPE*)d1;
	FT_TYPE n2 = *(FT_TYPE*)d2;
	if (n1 < n2)
		return (-1);
	else if (n1 == n2)
		return (0);
	return (1);
}

int	cmp_arr(void *d1, void *d2)
{
	FT_TYPE n1 = *(FT_TYPE*)d1;
	FT_TYPE n2 = *(FT_TYPE*)d2;
	return (n1 < n2);
}

void delete(void *data)
{
	free(data);
}

void	print_node(void *data)
{
	ft_printf("%d\n", *(int*)data);
}

bool 	ft_rbt_check_balance(t_tnode *root, t_rb_color prev_c)
{
	if (!root)
		return (true);
	if (prev_c == RB_RED && root->color == RB_RED)
		return (false);
	return (ft_rbt_check_balance(root->left, root->color) &&\
		ft_rbt_check_balance(root->right, root->color));
}

void	test_basic(void)
{
	FT_TYPE	val;
	t_rb_tree *tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
	size_t	size;
	srand(time(NULL));

	for (int i = 0; i < 15; ++i)
	{
		val = rand() % 200 - 100;
		ft_rbt_add(tree, &val);
	}
	assert(ft_rbt_size(tree) == 15);
	// ft_rbt_infix(tree, &print_node);
	ft_rbt_delete_tree(&tree);
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

# define BIG_NUM 400000

void	test_big_add(void)
{
	FT_TYPE	val;
	t_rb_tree *tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
	size_t	size;
	srand(time(NULL));

	for (int i = 0; i < BIG_NUM; ++i)
	{
		val = rand() % 200000000 - 100000000;
		ft_rbt_add(tree, &val);
	}
	assert(ft_rbt_size(tree) == BIG_NUM);
	// ft_rbt_infix(tree, &print_node);
	ft_rbt_delete_tree(&tree);
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

#define NUM_TESTS 1000

void	test_stress_add(void)
{
	FT_TYPE		val;
	size_t		size;

	srand(time(NULL));
	for  (int j = 0; j < NUM_TESTS; ++j)
	{
		t_rb_tree *tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
		size = rand() % 20000;
		for (int i = 0; i < size; ++i)
		{
			val = rand() % 200000000 - 100000000;
			ft_rbt_add(tree, &val);
		}
		assert(ft_rbt_size(tree) == size);
		ft_rbt_delete_tree(&tree);
	}
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

size_t		g_i;
FT_TYPE		g_test[1000];

void	add2arr(void *p)
{
	g_test[g_i++] = *(FT_TYPE*)p;
	// ft_printf("%d\n", *(FT_TYPE*)p);
}

void	print_darr(t_darr *arr)
{
	FT_TYPE val;

	ft_printf("size = %d, capacity = %lu\n", arr->size, arr->capacity);
	for (size_t i = 0; i < arr->size; ++i)
	{
		ft_da_get_value(arr, i, &val);
		ft_printf("%d\n", val);
	}
	ft_printf("\n");
}

void	test_distribution(void)
{
	t_darr		*arr;
	t_rb_tree	*tree;
	FT_TYPE		val;
	size_t		size;

	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		size = rand() % 1000;
		arr = ft_da_new(size, sizeof(FT_TYPE));
		tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
		for (size_t j = 0; j < size; ++j)
		{
			val = rand() % 20000 - 10000;
			ft_da_add(arr, &val);
			ft_rbt_add(tree, &val);
		}
		assert(arr->size == ft_rbt_size(tree));
		ft_da_sort(arr, &cmp_arr);
		// print_darr(arr);
		g_i = 0;
		ft_rbt_infix(tree, &add2arr);
		assert(!ft_memcmp(g_test, arr->array, sizeof(FT_TYPE) * g_i));
		ft_da_delete(&arr);
		ft_rbt_delete_tree(&tree);
	}
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

void	test_find(void)
{
	t_darr		*arr;
	t_rb_tree	*tree;
	FT_TYPE		v1, v2, v3;
	size_t		size;

	srand(time(NULL));
	size = rand() % 10000;
	arr = ft_da_new(size, sizeof(FT_TYPE));
	tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
	for (int i = 0; i < size; ++i)
	{
		v1 = rand() % 2000 - 1000;
		ft_rbt_add(tree, &v1);
		ft_da_add(arr, &v1);
	}
	assert(ft_rbt_size(tree) == arr->size);
	for (int i = 0; i < size; ++i)
	{
		v1 = *(FT_TYPE*)ft_da_get_pointer(arr, i);
		v2 = *(FT_TYPE*)ft_rbt_get_data(tree, &v1);
		ft_rbt_get_value(tree, &v1, &v3);
		assert(v1 == v2);
		assert(v1 == v3);
	}
	v1 = 2000000;
	assert(ft_rbt_get_data(tree, &v1) == NULL);
	ft_da_delete(&arr);
	ft_rbt_delete_tree(&tree);
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

void	test_balance(void)
{
	t_rb_tree	*tree;
	FT_TYPE		val;
	size_t		size;

	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		size = rand() % 1000;
		tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
		for (size_t j = 0; j < size; ++j)
		{
			val = rand() % 20000 - 10000;
			ft_rbt_add(tree, &val);
		}
		assert(size == ft_rbt_size(tree));
		assert(ft_rbt_check_balance(tree->root, RB_BLACK) == true);
		ft_rbt_delete_tree(&tree);
	}
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

void	test_delete_basic(void)
{
	FT_TYPE		val;
	size_t		size;
	t_rb_tree	*tree;
	t_darr		*arr;

	srand(time(NULL));
	size = rand() % 10000;
	tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
	arr = ft_da_new(10, sizeof(FT_TYPE));
	for  (int i = 0; i < size; ++i)
	{
		val = rand() % 2000;
		ft_da_add(arr, &val);
		ft_rbt_add(tree, &val);
	}
	assert(ft_rbt_size(tree) == size);
	assert(arr->size == size);
	for (int i = 0; i < size; ++i)
	{
		val = *(FT_TYPE*)ft_da_get_pointer(arr, i);
		ft_rbt_delete_val(tree, &val);
	}
	assert(ft_rbt_size(tree) == 0);
	ft_memset(tree, 0, sizeof(t_rb_tree));
	free(tree);
	ft_da_delete(&arr);
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

void	test_delete_and_balance(void)
{
	t_darr		*arr;
	t_rb_tree	*tree;
	FT_TYPE		val;
	size_t		size;

	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		size = rand() % 10000;
		arr = ft_da_new(size, sizeof(FT_TYPE));
		tree = ft_rbt_new(sizeof(FT_TYPE), &cmp_tree, &delete);
		for (size_t j = 0; j < size; ++j)
		{
			val = rand() % 20000 - 10000;
			ft_da_add(arr, &val);
			ft_rbt_add(tree, &val);
		}
		for (size_t j = 0; j < size; ++j)
		{
			val = *(FT_TYPE*)ft_da_get_pointer(arr, j);
			ft_rbt_delete_val(tree, &val);
			// assert(ft_rbt_check_balance(tree->root, RB_BLACK) == true);
		}
		ft_da_delete(&arr);
		ft_rbt_delete_tree(&tree);
	}
	ft_printf("{green}%s = OK{eoc}\n", __ASSERT_FUNCTION);
}

int main(void)
{
	ft_printf("size tree = %lu, size node = %lu\n",\
				sizeof(t_rb_tree), sizeof(t_tnode));
	// test_basic();
	// test_big_add();
	// test_stress_add();
	// test_distribution();
	// test_find();
	// test_balance();
	// test_delete_basic();
	test_delete_and_balance();
	return (EXIT_SUCCESS);
}
