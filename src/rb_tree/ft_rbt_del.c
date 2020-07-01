/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:18:25 by astripeb          #+#    #+#             */
/*   Updated: 2020/07/01 13:02:19 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbt_hidden.h"

static void	swap(t_tnode *n1, t_tnode *n2)
{
	void		*temp;

	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
}


void		normalize(t_rb_tree *tree, t_tnode *node)
{
	t_tnode *brother;

	while (node != tree->root && !isred(node))
	{
		if (node == L_SON)
		{
			brother = R_SON;
			if (isred(brother))
			{
				brother->color = RB_BLACK;
				FATHER->color = RB_RED;
				rotate_left(tree, FATHER);
				brother = R_SON;
			}
			if (brother && !isred(brother->left) && !isred(brother->right))
			{
				brother->color = RB_RED;
				node = FATHER;
			}
			else
			{
				if (brother)
				{
					if (!isred(R_NEPHEW))
					{
						L_NEPHEW->color = RB_BLACK;
						brother->color = RB_RED;
						rotate_right(tree, brother);
						brother = FATHER->right;
					}
					FATHER->color = RB_BLACK;
					brother->color = FATHER->color;
					R_NEPHEW->color = RB_BLACK;
					rotate_left(tree, FATHER);
				}
				node = tree->root;
			}
		}
		else
		{
			brother = L_SON;
			if (isred(brother))
			{
				brother->color = RB_BLACK;
				FATHER->color = RB_RED;
				rotate_right(tree, FATHER);
				brother = L_SON;
			}
			if (brother && !isred(brother->left) && !isred(brother->right))
			{
				brother->color = RB_RED;
				node = FATHER;
			}
			else
			{
				if (brother)
				{
					if (!isred(L_NEPHEW))
					{
						R_NEPHEW->color = RB_BLACK;
						brother->color = RB_RED;
						rotate_left(tree, brother);
						brother = FATHER->left;
					}
					FATHER->color = RB_BLACK;
					brother->color = FATHER->color;
					L_NEPHEW->color = RB_BLACK;
					rotate_right(tree, FATHER);
				}
				node = tree->root;
			}
		}
	}
	node->color = RB_BLACK;
	tree->root->color = RB_BLACK;
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
		normalize(tree, temp);
	tree->size -= 1;
	del_one_node(y, tree->del);
}
