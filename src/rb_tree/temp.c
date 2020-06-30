/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:31:34 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/30 16:31:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

t_tnode	*get_brother(t_tnode *node)
{
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}

void	delete_case6(t_tnode **root, t_tnode *node)
{
	t_tnode	*brother;

	brother = get_brother(node);
	brother->color = node->parent->color;
	node->parent->color = RB_BLACK;

	if (node == node->parent->left)
	{
		brother->right->color = RB_BLACK;
		rotate_left(root, node->parent);
	}
	else
	{
		brother->left->color = RB_BLACK;
		rotate_right(root, node->parent);
	}
}

void	delete_case5(t_tnode **root, t_tnode *node)
{
	t_tnode	*brother;

	brother = get_brother(node);
	if (brother->color == RB_BLACK)
	{
		if ((node == L_SON) &&\
		!isred(brother->right) && isred(brother->left))
		{
			brother->color = RB_RED;
			brother->left->color = RB_BLACK;
			rotate_right(root, brother);
		}
		else if ((node == R_SON) &&\
		!isred(brother->left) && isred(brother->right))
		{
			brother->color = RB_RED;
			brother->right->color = RB_BLACK;
			rotate_left(root, brother);
		}
	}
	delete_case6(root, node);
}

void	delete_case4(t_tnode **root, t_tnode *node)
{
	t_tnode	*brother;

	brother = get_brother(node);
	if (isred(node->parent) && !isred(brother) &&\
	!isred(brother->left) && !isred(brother->right))
	{
		brother->color = RB_RED;
		node->parent->color = RB_BLACK;
	}
	else
		delete_case5(root, node);
}

void	delete_case3(t_tnode **root, t_tnode *node)
{
	t_tnode	*brother;

	brother = get_brother(node);
	if (!isred(node->parent) && !isred(brother) &&\
	!isred(brother->left) && !isred(brother->right))
	{
		brother->color = RB_RED;
		delete_case1(root, node->parent);
	}
	else
		delete_case4(root, node);
}

void	delete_case2(t_tnode **root, t_tnode *node)
{
	t_tnode	*brother;

	brother = get_brother(node);
	if (isred(brother))
	{
		brother->color = RB_BLACK;
		node->parent->color = RB_RED;
		if (node == node->parent->left)
			rotate_left(root, node);
		else
			rotate_right(root, node);
	}
	delete_case3(root, node);
}

void	delete_case1(t_tnode **root, t_tnode *node)
{
	if (node->parent != NULL)
		delete_case2(root, node);
}
