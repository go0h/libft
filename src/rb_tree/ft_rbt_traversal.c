/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_traversal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 21:04:35 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 19:17:27 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

static void	prefix_order(t_tnode *node, void (*f)(void *))
{
	if (node == NULL)
		return ;
	f(node->content);
	prefix_order(node->left, f);
	prefix_order(node->right, f);
}

static void	infix_order(t_tnode *node, void (*f)(void *))
{
	if (node == NULL)
		return ;
	infix_order(node->left, f);
	f(node->content);
	infix_order(node->right, f);
}

void		ft_rbt_prefix(t_rb_tree *tree, void (*f)(void *))
{
	prefix_order(tree->root, f);
}

void		ft_rbt_infix(t_rb_tree *tree, void (*f)(void *))
{
	infix_order(tree->root, f);
}

void		ft_rbt_suffix(t_rb_tree *tree, void (*f)(void *))
{
	suffix_order(tree->root, f);
}
