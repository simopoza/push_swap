/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:00:49 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 01:08:48 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_those_moves(int *tmp, t_list **stack_a, t_list **stack_b)
{
	if (tmp[0] * tmp[1] == 0)
		apply_on_zero(tmp, stack_a, stack_b);
	if ((tmp[0] * tmp[1]) < 0)
		apply_on_different_sign(tmp, stack_a, stack_b);
	if (tmp[0] * tmp[1] > 0)
		apply_on_same_sign(tmp, stack_a, stack_b);
	free (tmp);
	push_a(stack_a, stack_b);
	index_stack(*stack_a);
	index_stack(*stack_b);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	*tmp;
	int	len;
	int	i;

	i = 0;
	len = count_node((*stack_b));
	while (i < len)
	{
		tmp = best_moves(stack_a, stack_b);
		apply_those_moves(tmp, stack_a, stack_b);
		i++;
	}
}
