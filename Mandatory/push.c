/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:49 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:04:24 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int	data;

	if (is_empty(*stack_a) == 0)
		return ;
	data = del_first_node(stack_a);
	add_at_front(stack_b, data);
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int	data;

	if (is_empty(*stack_b) == 0)
		return ;
	data = del_first_node(stack_b);
	add_at_front(stack_a, data);
	ft_putstr_fd("pa\n", 1);
}
