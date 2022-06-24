/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:55:48 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:10:28 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	moves_a(int pos_a, t_list *stack_a)
{
	int	moves;

	if (pos_a > count_node(stack_a) / 2)
		moves = -(count_node(stack_a) - pos_a + 1);
	else
		moves = pos_a - 1;
	return (moves);
}

int	help_moves_in_a(t_list *stack_a, int data, int pos_a, int i)
{
	t_list	*tmp1;

	tmp1 = stack_a->next;
	while (tmp1->next)
	{
		if (tmp1->data < data && tmp1->next->data > data)
			pos_a = i + 1;
		i++;
		tmp1 = tmp1->next;
	}
	return (moves_a(pos_a, stack_a));
}

int	moves_in_a(int data, t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		pos_a;
	int		i;

	i = 2;
	pos_a = 0;
	tmp1 = stack_a;
	tmp = ft_lstlastt(tmp1);
	if (data > max_in_stack(stack_a))
	{
		pos_a = position(&stack_a, max_in_stack(stack_a)) + 2;
		return (moves_a(pos_a, stack_a));
	}
	if (stack_a->data > data && data > tmp->data)
		return (0);
	if (stack_a->data < data && stack_a->next->data > data)
		return (moves_a(i, stack_a));
	return (help_moves_in_a(stack_a, data, pos_a, i));
}

int	moves_in_b(int pos_b, t_list *stack_b)
{
	int	moves;

	if (pos_b > count_node(stack_b) / 2)
		moves = -(count_node(stack_b) - pos_b + 1);
	else
		moves = pos_b - 1;
	return (moves);
}
