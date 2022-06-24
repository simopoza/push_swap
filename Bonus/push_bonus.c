/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:29:37 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 18:43:56 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_b_bonus(t_list **stack_a, t_list **stack_b)
{
	int	data;

	if (*stack_a != NULL)
	{
		data = del_first_node(stack_a);
		add_at_front(stack_b, data);
	}
}

void	ft_push_a_bonus(t_list **stack_a, t_list **stack_b)
{
	int	data;

	if (*stack_b != NULL)
	{
		data = del_first_node(stack_b);
		add_at_front(stack_a, data);
	}
}
