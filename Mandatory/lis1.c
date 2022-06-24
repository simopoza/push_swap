/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:19:34 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:06:14 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	position(t_list **stack, int data)
{
	t_list	*tmp;
	int		index;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->data == data)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

void	help_find_list(t_list *stack_a)
{
	t_list	*perv;

	perv = stack_a;
	while (perv)
	{
		perv->arr = NULL;
		perv = perv->next;
	}
}

t_help	*find_lis(t_list *stack_a)
{
	t_list	*curr;
	t_list	*perv;

	help_find_list(stack_a);
	perv = stack_a;
	perv->arr = create_node1(perv->data);
	curr = stack_a->next;
	while (curr)
	{
		perv = stack_a;
		while (perv != curr)
		{
			if (curr->data > perv->data
				&& count_node1(perv->arr) > count_node1(curr->arr))
			{
				if (curr->arr)
					free_list(curr->arr);
				curr->arr = copy_list(perv->arr);
			}
			perv = perv->next;
		}
		curr->arr = ft_join_arr(curr->arr, curr->data);
		curr = curr->next;
	}
	return (ft_find_max_arr(stack_a));
}
