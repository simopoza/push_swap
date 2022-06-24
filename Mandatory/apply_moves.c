/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:18:12 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:07:07 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_on_top(int tmp_a, int tmp_b, t_list **stack_a, t_list **stack_b)
{
	while (tmp_a && tmp_b)
	{
		rr(stack_a, stack_b, "rr\n");
		tmp_a--;
		tmp_b--;
	}
	while (tmp_a--)
		ra_rb(stack_a, "ra\n");
	while (tmp_b--)
		ra_rb(stack_b, "rb\n");
}

void	apply_on_bot(int tmp_a, int tmp_b, t_list **stack_a, t_list **stack_b)
{
	while (tmp_a && tmp_b)
	{
		rrr(stack_a, stack_b, "rrr\n");
		tmp_a--;
		tmp_b--;
	}
	while (tmp_a--)
		rra_rrb(stack_a, "rra\n");
	while (tmp_b--)
		rra_rrb(stack_b, "rrb\n");
}

void	apply_on_same_sign(int *tmp, t_list **stack_a, t_list **stack_b)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = abs(tmp[0]);
	tmp_b = abs(tmp[1]);
	if (tmp[0] > 0)
		apply_on_top(tmp_a, tmp_b, stack_a, stack_b);
	if (tmp[0] < 0)
		apply_on_bot(tmp_a, tmp_b, stack_a, stack_b);
}

void	apply_on_different_sign(int *tmp, t_list **stack_a, t_list **stack_b)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = abs(tmp[0]);
	tmp_b = abs(tmp[1]);
	if (tmp[0] < 0)
	{
		while (tmp_a--)
			rra_rrb(stack_a, "rra\n");
		while (tmp_b--)
			ra_rb(stack_b, "rb\n");
	}
	else
	{
		while (tmp_a--)
			ra_rb(stack_a, "ra\n");
		while (tmp_b--)
			rra_rrb(stack_b, "rrb\n");
	}
}
