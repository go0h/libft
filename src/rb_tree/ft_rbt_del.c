/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:18:25 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 19:25:48 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

static void		red_brother(t_rb_tree *tree, t_tnode *node, t_tnode *brother)
{
	brother->color = RB_BLACK;
	FATHER->color = RB_RED;
	if (node == L_SON)
		rotate_left(tree, FATHER);
	else
		rotate_right(tree, FATHER);
}

static t_tnode	*left_case(t_rb_tree *tree, t_tnode *node, t_tnode *brother)
{
	if (brother && !isred(brother->left) && !isred(brother->right))
	{
		brother->color = RB_RED;
		node = FATHER;
	}
	else
	{
		if (brother)
		{
			if (!isred(R_NEPHEW))
			{
				L_NEPHEW->color = RB_BLACK;
				brother->color = RB_RED;
				rotate_right(tree, brother);
				brother = FATHER->right;
			}
			FATHER->color = RB_BLACK;
			brother->color = FATHER->color;
			R_NEPHEW->color = RB_BLACK;
			rotate_left(tree, FATHER);
		}
		node = tree->root;
	}
	return (node);
}

static t_tnode	*right_case(t_rb_tree *tree, t_tnode *node, t_tnode *brother)
{
	if (brother && !isred(brother->left) && !isred(brother->right))
	{
		brother->color = RB_RED;
		node = FATHER;
	}
	else
	{
		if (brother)
		{
			if (!isred(L_NEPHEW))
			{
				R_NEPHEW->color = RB_BLACK;
				brother->color = RB_RED;
				rotate_left(tree, brother);
				brother = FATHER->left;
			}
			FATHER->color = RB_BLACK;
			brother->color = FATHER->color;
			L_NEPHEW->color = RB_BLACK;
			rotate_right(tree, FATHER);
		}
		node = tree->root;
	}
	return (node);
}

static void		normalize(t_rb_tree *tree, t_tnode *node)
{
	t_tnode *brother;

	while (node != tree->root && !isred(node))
	{
		if (node == L_SON)
		{
			brother = R_SON;
			if (isred(brother))
				red_brother(tree, node, brother);
			node = left_case(tree, node, R_SON);
		}
		else
		{
			brother = L_SON;
			if (isred(brother))
				red_brother(tree, node, brother);
			node = right_case(tree, node, L_SON);
		}
	}
	node->color = RB_BLACK;
}

void			ft_rbt_delete_val(t_rb_tree *tree, void *data)
{
	t_tnode	*x;
	t_tnode	*y;
	t_tnode	*child;

	if (!(x = ft_rbt_get_node(tree, data)))
		return ;
	if (x->left == NULL || x->right == NULL)
		y = x;
	else
	{
		y = x->right;
		while (y->left != NULL)
			y = y->left;
	}
	child = y->left ? y->left : y->right;
	replace_node(tree, y, child);
	if (x != y)
		swap_content(x, y);
	if (child && y->color == RB_BLACK)
		normalize(tree, child);
	tree->size -= 1;
	tree->del(y->content);
	ft_memset(y, 0, sizeof(t_tnode));
	free(y);
}
