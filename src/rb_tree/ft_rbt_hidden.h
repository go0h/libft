/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_hidden.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:13:38 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/26 20:43:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBT_HIDDEN_H
# define FT_RBT_HIDDEN_H

# include "ft_rbtree.h"
# include <stdio.h>

# define FATHER		(node->parent)
# define GRFATHER	(node->parent->parent)
# define L_UNCLE	(node->parent->parent->left)
# define R_UNCLE	(node->parent->parent->right)
# define L_SON		(node->parent->left)
# define R_SON		(node->parent->right)
# define L_NEPHEW	(brother->left)
# define R_NEPHEW	(brother->right)

void		rotate_right(t_tnode **root, t_tnode *node);

void		rotate_left(t_tnode **root, t_tnode *node);

size_t		get_size(t_tnode *node);

t_tnode		*ft_rbt_get_node(t_rb_tree *tree, void *data);

void		prefix_order(t_tnode *node, void (*f)(void *));

void		infix_order(t_tnode *node, void (*f)(void *));

#endif
