/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_add_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:36:52 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 19:37:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

static t_tnode	*case_left(t_rb_tree *tree, t_tnode *node)
{
	t_tnode *uncle;

	uncle = R_UNCLE;
	if (isred(uncle))
	{
		FATHER->color = RB_BLACK;
		uncle->color = RB_BLACK;
		GRFATHER->color = RB_RED;
		node = GRFATHER;
	}
	else
	{
		if (node == R_SON)
		{
			node = node->parent;
			rotate_left(tree, node);
		}
		FATHER->color = RB_BLACK;
		GRFATHER->color = RB_RED;
		rotate_right(tree, GRFATHER);
	}
	return (node);
}

static t_tnode	*case_right(t_rb_tree *tree, t_tnode *node)
{
	t_tnode *uncle;

	uncle = L_UNCLE;
	if (isred(uncle))
	{
		FATHER->color = RB_BLACK;
		uncle->color = RB_BLACK;
		GRFATHER->color = RB_RED;
		node = GRFATHER;
	}
	else
	{
		if (node == L_SON)
		{
			node = node->parent;
			rotate_right(tree, node);
		}
		FATHER->color = RB_BLACK;
		GRFATHER->color = RB_RED;
		rotate_left(tree, GRFATHER);
	}
	return (node);
}

static void		normalize(t_rb_tree *tree, t_tnode *node)
{
	while (node != tree->root && isred(FATHER) && GRFATHER)
	{
		if (FATHER == L_UNCLE)
			node = case_left(tree, node);
		else
			node = case_right(tree, node);
	}
	tree->root->color = RB_BLACK;
}

void			add_node(t_rb_tree *tree, t_tnode *new)
{
	t_tnode *temp;
	t_tnode *parent;

	parent = NULL;
	temp = tree->root;
	while (temp != NULL)
	{
		parent = temp;
		temp = tree->cmp(new->content, temp->content) <= 0 \
					? temp->left : temp->right;
	}
	new->parent = parent;
	if (tree->cmp(new->content, parent->content) <= 0)
		parent->left = new;
	else
		parent->right = new;
	normalize(tree, new);
}
