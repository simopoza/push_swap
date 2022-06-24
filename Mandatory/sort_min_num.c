/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:34:55 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:02:30 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_help_sort_3(t_list **stack_a, int data)
{
	if ((*stack_a)->data < data)
		sa_sb(stack_a, "sa\n");
	if ((*stack_a)->data > data)
		ra_rb(stack_a, "ra\n");
}

void	sort_3_num(t_list **stack_a)
{
	int	data;

	data = (*stack_a)->next->next->data;
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < data)
		ft_help_sort_3(stack_a, data);
	if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > data)
	{
		if ((*stack_a)->data < data)
		{
			sa_sb(stack_a, "sa\n");
			ra_rb(stack_a, "ra\n");
		}
		if ((*stack_a)->data > data)
			rra_rrb(stack_a, "rra\n");
	}
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > data)
	{
		sa_sb(stack_a, "sa\n");
		rra_rrb(stack_a, "rra\n");
	}
}
