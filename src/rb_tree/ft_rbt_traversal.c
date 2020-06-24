/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_traversal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 21:04:35 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/24 15:03:30 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

void		ft_rbt_prefix(t_rb_tree *tree, void (*f)(void *))
{
	prefix_order(tree->root, f);
}

void		ft_rbt_infix(t_rb_tree *tree, void (*f)(void *))
{
	infix_order(tree->root, f);
}

static void	suffix_order(t_tnode *node, void (*f)(void *))
{
	if (!node)
		return ;
	suffix_order(node->left, f);
	suffix_order(node->right, f);
	f(node->content);
}

void		ft_rbt_suffix(t_rb_tree *tree, void (*f)(void *))
{
	suffix_order(tree->root, f);
}
