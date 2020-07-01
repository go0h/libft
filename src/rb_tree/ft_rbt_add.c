/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:12:04 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 21:29:22 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

bool			ft_rbt_add(t_rb_tree *tree, void *content)
{
	t_tnode	*new;

	if (!tree || !(new = ft_rbt_new_node(content, tree->cont_size)))
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

bool			ft_rbt_add_node(t_rb_tree *tree, t_tnode *new)
{
	if (!tree || !new)
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

bool			ft_rbt_move_cont(t_rb_tree *tree, void *content)
{
	t_tnode	*new;

	if (!tree || !(new = ft_memalloc(sizeof(t_tnode))))
		return (false);
	new->content = content;
	new->color = RB_RED;
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
