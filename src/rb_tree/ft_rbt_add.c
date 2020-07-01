/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:12:04 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 09:29:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

static void		normalize(t_rb_tree *tree, t_tnode *node)
{
	t_tnode *uncle;

	if (node == tree->root)
		return ;
	while (isred(FATHER) && GRFATHER)
	{
		if (FATHER == L_UNCLE)
		{
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
		}
		else
		{
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
		}
	}
	tree->root->color = RB_BLACK;
}


static void		add_node(t_rb_tree *tree, t_tnode *new)
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

bool		ft_rbt_add(t_rb_tree *tree, void *data)
{
	t_tnode	*new;

	if (!tree || !(new = ft_rbt_new_node(data, tree->cont_size)))
		return (false);
	if (!tree->root)
	{
		tree->root = new;
		tree->root->color = RB_BLACK;
	}
	else
		add_node(tree, new);
	tree->size += 1;
	return (true);
}
