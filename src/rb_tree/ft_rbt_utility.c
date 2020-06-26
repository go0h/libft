/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:08:37 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/25 16:46:06 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

void	*ft_rbt_get_data(t_rb_tree *tree, void *data)
{
	int		ret;
	t_tnode	*node;

	node = tree->root;
	while (node != NULL)
	{
		ret = tree->cmp(data, node->content);
		if (!ret)
			return (node->content);
		node = ret < 0 ? node->left : node->right;
	}
	return (NULL);
}

t_tnode	*ft_rbt_get_node(t_rb_tree *tree, void *data)
{
	int		ret;
	t_tnode	*node;

	node = tree->root;
	while (node != NULL)
	{
		ret = tree->cmp(data, node->content);
		if (!ret)
			return (node);
		node = ret < 0 ? node->left : node->right;
	}
	return (NULL);
}

void	ft_rbt_get_value(t_rb_tree *tree, void *data, void *value)
{
	int		ret;
	t_tnode	*node;

	node = tree->root;
	while (node != NULL)
	{
		ret = tree->cmp(data, node->content);
		if (!ret)
		{
			ft_memcpy(value, node->content, tree->cont_size);
			break ;
		}
		node = ret < 0 ? node->left : node->right;
	}
}
