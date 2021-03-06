/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_hidden.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:12:42 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 19:15:32 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

void	rotate_left(t_rb_tree *tree, t_tnode *y)
{
	t_tnode	*x;

	x = y->right;
	y->right = x->left;
	x->parent = y->parent;
	if (x->left != NULL)
		x->left->parent = y;
	if (x->parent != NULL)
	{
		if (y == x->parent->left)
			x->parent->left = x;
		else
			x->parent->right = x;
	}
	else
		tree->root = x;
	x->left = y;
	if (y != NULL)
		y->parent = x;
}

void	rotate_right(t_rb_tree *tree, t_tnode *y)
{
	t_tnode	*x;

	x = y->left;
	y->left = x->right;
	x->parent = y->parent;
	if (x->right != NULL)
		x->right->parent = y;
	if (x->parent != NULL)
	{
		if (y == x->parent->left)
			x->parent->left = x;
		else
			x->parent->right = x;
	}
	else
		tree->root = x;
	x->right = y;
	if (x != NULL)
		y->parent = x;
}

size_t	get_size(t_tnode *node)
{
	if (node == NULL)
		return (0);
	return (get_size(node->left) + get_size(node->right) + 1);
}

void	swap_content(t_tnode *n1, t_tnode *n2)
{
	void		*temp;

	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
}

void	replace_node(t_rb_tree *tree, t_tnode *y, t_tnode *child)
{
	if (child)
		child->parent = y->parent;
	if (y->parent == NULL)
		tree->root = child;
	else
	{
		if (y == y->parent->left)
			y->parent->left = child;
		else
			y->parent->right = child;
	}
}
