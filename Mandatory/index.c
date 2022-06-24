/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:00:43 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 21:30:06 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_stack(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

int	max_in_stack(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = stack->data;
	while (tmp)
	{
		if (max <= tmp->data)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	min_in_stack(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = stack->data;
	while (tmp)
	{
		if (min >= tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
