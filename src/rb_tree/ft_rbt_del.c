/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:18:25 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/26 21:02:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

static void	swap(t_tnode *n1, t_tnode *n2)
{
	void		*temp;
	t_rb_color	tc;

	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
	tc = n1->color;
	n1->color = n2->color;
	n2->color = tc;
}

void	del_one_node(t_tnode *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->content);
	ft_memset(node, 0, sizeof(t_tnode));
	free(node);
}

static inline bool black_nephews(t_tnode *brother)
{
	if (brother == NULL)
		return (false);
	if (L_NEPHEW == NULL && R_NEPHEW == NULL)
		return (true);
	else if (L_NEPHEW == NULL)
		return (R_NEPHEW->color == RB_BLACK);
	else if (R_NEPHEW == NULL)
		return (L_NEPHEW->color == RB_BLACK);
	return (L_NEPHEW->color == RB_BLACK && R_NEPHEW->color == RB_BLACK);
}

void		normalize(t_tnode **root, t_tnode *node)
{
	t_tnode *brother;

	while (node != *root && FATHER && node->color == RB_BLACK)
	{
		if (node == L_SON)
		{
			brother = FATHER->right;
			if (brother && brother->color == RB_RED)
			{
				brother->color = RB_BLACK;
				FATHER->color = RB_RED;
				rotate_left(root, FATHER);
				brother = FATHER->right;
			}
			if (black_nephews(brother))
			{
				brother->color = RB_RED;
				node = FATHER;
			}
			else
			{
				if (R_NEPHEW->color == RB_BLACK)
				{
					L_NEPHEW->color = RB_BLACK;
					brother->color = RB_RED;
					rotate_right(root, brother);
					brother = FATHER->right;
				}
				brother->color = FATHER->color;
				FATHER->color = RB_BLACK;
				R_NEPHEW->color = RB_BLACK;
				rotate_left(root, FATHER);
				node = *root;
			}
		}
		else
		{
			brother = FATHER->left;
			if (brother && brother->color == RB_RED)
			{
				brother->color = RB_BLACK;
				FATHER->color = RB_RED;
				rotate_right(root, FATHER);
				brother = FATHER->left;
			}
			if (black_nephews(brother))
			{
				brother->color = RB_RED;
				node = FATHER;
			}
			else
			{
				if (L_NEPHEW->color == RB_BLACK)
				{
					R_NEPHEW->color = RB_BLACK;
					brother->color = RB_RED;
					rotate_left(root, brother);
					brother = FATHER->left;
				}
				brother->color = FATHER->color;
				L_NEPHEW->color = RB_BLACK;
				FATHER->color = RB_BLACK;
				rotate_right(root, FATHER);
				node = *root;
			}
		}
	}
	node->color = RB_BLACK;
}

/*
**	Если у неё только один ребёнок, то делаем у
**	родителя ссылку на него вместо этой вершины.
**
**	Если же имеются оба ребёнка,
**	то находим вершину со следующим значением ключа.
**	У такой вершины нет левого ребёнка
**	(так как такая вершина находится в правом поддереве исходной
**	вершины и она самая левая в нем, иначе бы мы взяли ее левого ребенка.
**	Иными словами сначала мы переходим в правое поддерево,
**	а после спускаемся вниз в левое до тех пор,
**	пока у вершины есть левый ребенок).
**	Удаляем уже эту вершину описанным во втором пункте способом,
**	скопировав её ключ в изначальную вершину.
*/

void	ft_rbt_delete_val(t_rb_tree *tree, void *data)
{
	t_tnode	*x;
	t_tnode	*y;
	t_tnode	*temp;

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
	temp = y->left ? y->left : y->right;
	if (temp)
		temp->parent = y->parent;
	if (y->parent == NULL)
		tree->root = temp;
	else
	{
		if (y == y->parent->left)
			y->parent->left = temp;
		else
			y->parent->right = temp;
	}
	if (x != y)
		swap(x, y);
	if (y->color == RB_BLACK && temp)
		normalize(&tree->root, temp);
	tree->size -= 1;
	del_one_node(y, tree->del);
}
