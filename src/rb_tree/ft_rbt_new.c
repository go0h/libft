/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:51:03 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 09:31:24 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

t_rb_tree	*ft_rbt_new(size_t cont_size, int (*cmp)(void *, void *),
						void (*del)(void *))
{
	t_rb_tree	*tree;

	if (!(tree = (t_rb_tree*)ft_memalloc(sizeof(t_rb_tree))))
		return (NULL);
	tree->cmp = cmp;
	tree->del = del;
	tree->cont_size = cont_size;
	return (tree);
}

t_tnode		*ft_rbt_new_node(void *content, size_t cont_size)
{
	t_tnode	*node;

	if (!(node = (t_tnode*)ft_memalloc(sizeof(t_tnode))))
		return (NULL);
	if (!(node->content = ft_memalloc(cont_size)))
	{
		free(node);
		return (NULL);
	}
	node->color = RB_RED;
	ft_memcpy(node->content, content, cont_size);
	return (node);
}

static void	del_subtree(t_rb_tree *tree, t_tnode *node)
{
	if (node == NULL)
		return ;
	del_subtree(tree, node->left);
	del_subtree(tree, node->right);
	tree->del(node->content);
	ft_memset(node, 0, sizeof(t_tnode));
	free(node);
}

void		ft_rbt_delete_tree(t_rb_tree **tree)
{
	if (!tree || !*tree)
		return ;
	del_subtree(*tree, (*tree)->root);
	ft_memset(*tree, 0, sizeof(t_rb_tree));
	free(*tree);
}

size_t		ft_rbt_size(t_rb_tree *tree)
{
	if (!tree)
		return (0);
	tree->size = get_size(tree->root);
	return (tree->size);
}
