/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_hidden.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:12:42 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/24 15:02:32 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

void	rotate_right(t_tnode **root, t_tnode *y)
{
	t_tnode	*x;

	x = y->left;
	x->parent = y->parent;
	y->parent = x;
	y->left = x->right;
	if (x->parent != NULL)
	{
		if (y == x->parent->left)
			x->parent->left = x;
		else
			x->parent->right = x;
	}
	else
		*root = x;
	if (y->left != NULL)
		y->left->parent = y;
	x->right = y;
}

void	rotate_left(t_tnode **root, t_tnode *y)
{
	t_tnode	*x;

	x = y->right;
	x->parent = y->parent;
	y->parent = x;
	y->right = x->left;
	if (x->parent != NULL)
	{
		if (y == x->parent->left)
			x->parent->left = x;
		else
			x->parent->right = x;
	}
	else
		*root = x;
	if (y->right != NULL)
		y->right->parent = y;
	x->left = y;
}

size_t	get_size(t_tnode *node)
{
	if (node == NULL)
		return (0);
	return (get_size(node->left) + get_size(node->right) + 1);
}

void	prefix_order(t_tnode *node, void (*f)(void *))
{
	if (!node)
		return ;
	f(node->content);
	prefix_order(node->left, f);
	prefix_order(node->right, f);
}

void	infix_order(t_tnode *node, void (*f)(void *))
{
	if (!node)
		return ;
	infix_order(node->left, f);
	f(node->content);
	infix_order(node->right, f);
}
