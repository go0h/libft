/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:46:36 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/24 22:47:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H

# include "ft_memory.h"
# include "stdbool.h"

typedef enum	e_rb_color
{
	RB_RED,
	RB_BLACK
}				t_rb_color;

typedef struct	s_tnode
{
	struct s_tnode	*parent;
	struct s_tnode	*left;
	struct s_tnode	*right;
	void			*content;
	t_rb_color		color;
}				t_tnode;

typedef struct	s_rb_tree
{
	struct s_tnode	*root;
	size_t			size;
	size_t			cont_size;
	int				(*cmp)(void *, void *);
	void			(*del)(void *);
}				t_rb_tree;

t_rb_tree		*ft_rbt_new(size_t cont_size, int (*cmp)(void *, void *),\
						void (*del)(void *));

t_tnode			*ft_rbt_new_node(void *content, size_t cont_size);

bool			ft_rbt_add(t_rb_tree *tree, void *data);

void			ft_rbt_delete_tree(t_rb_tree **tree);

size_t			ft_rbt_size(t_rb_tree *tree);

void			*ft_rbt_get_data(t_rb_tree *tree, void *data);

void			ft_rbt_get_value(t_rb_tree *tree, void *data, void *value);

void			ft_rbt_delete_val(t_rb_tree *tree, void *data);

/*
**	Traversal
*/

void			ft_rbt_prefix(t_rb_tree *tree, void (*f)(void *));

void			ft_rbt_infix(t_rb_tree *tree, void (*f)(void *));

void			ft_rbt_suffix(t_rb_tree *tree, void (*f)(void *));


#endif
