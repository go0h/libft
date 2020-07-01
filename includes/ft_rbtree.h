/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:46:36 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 21:30:28 by astripeb         ###   ########.fr       */
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

/*
**	RED-BLACK TREE STRUCTURE
**
**	root		- root node of tree
**	size		- number of elements, stored in tree
**	cont_size	- size of content, strored in node in BYTES
**	CMP			- compare function.
**				Returns
**				 0 if content equal
**				-1 if content less
**				 1 if content more
**	DEL			- funtion to delete content stored in tree's node
*/

typedef struct	s_rb_tree
{
	struct s_tnode	*root;
	size_t			size;
	size_t			cont_size;
	int				(*cmp)(void *, void *);
	void			(*del)(void *);
}				t_rb_tree;

/*
**	NEW RED-BLACK TREE
**	Сreate a new tree
**	cont_size in BYTES.
**	CMP			- compare function.
**				Whitch returns:
**					 0 if content equal
**					-1 if content less
**					 1 if content more
**	DEL			- funtion to delete content stored in tree's node
*/

t_rb_tree		*ft_rbt_new(size_t cont_size, int (*cmp)(void *, void *),\
						void (*del)(void *));

/*
**	Creates new node and allocate new memory for content
**	On error return NULL
*/

t_tnode			*ft_rbt_new_node(void *content, size_t cont_size);

/*
**	Creates new node and allocate new memory for content
**	Add to tree
**	On error return false
*/

bool			ft_rbt_add(t_rb_tree *tree, void *content);

/*
**	Creates new node and and move content to node.
**	Add to tree. Memory for content is not allocated.
**	On error return false
*/

bool			ft_rbt_move_cont(t_rb_tree *tree, void *content);

/*
**	Add new node to tree
**	On error return false
*/

bool			ft_rbt_add_node(t_rb_tree *tree, t_tnode *new);

/*
**	Delete tree node with DEL funcs
*/

void			ft_rbt_delete_tree(t_rb_tree **tree);

/*
**	Return number of nodes stored in tree
*/

size_t			ft_rbt_size(t_rb_tree *tree);

/*
**	Find node with CMP function and return point to content
**	On error return NULL
*/

void			*ft_rbt_get_data(t_rb_tree *tree, void *data);

/*
**	Find node with CMP function and copy content to value
**	Size of value must be the same with size of data
*/

void			ft_rbt_get_value(t_rb_tree *tree, void *data, void *value);

/*
**	Find node with CMP function and delete content with DEL function
**	Size of value must be the same with size of data
*/

void			ft_rbt_delete_val(t_rb_tree *tree, void *data);

/*
**	Traversal functions
*/

void			ft_rbt_prefix(t_rb_tree *tree, void (*f)(void *));

void			ft_rbt_infix(t_rb_tree *tree, void (*f)(void *));

void			ft_rbt_suffix(t_rb_tree *tree, void (*f)(void *));

#endif
