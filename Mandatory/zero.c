/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:37:09 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 17:56:34 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	help_on_zero(int *tmp, t_list **stack_a)
{
	int	i;

	if (tmp[0] > 0)
	{
		i = 0;
		while (i++ < abs(tmp[0]))
			ra_rb(stack_a, "ra\n");
	}
	else
	{
		i = 0;
		while (i++ < abs(tmp[0]))
			rra_rrb(stack_a, "rra\n");
	}
}

void	apply_on_zero(int *tmp, t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (tmp[0] == 0 && tmp[1] == 0)
		return ;
	if (tmp[0] == 0)
	{
		if (tmp[1] > 0)
		{
			i = 0;
			while (i++ < abs(tmp[1]))
				ra_rb(stack_b, "rb\n");
		}
		else
		{
			i = 0;
			while (i++ < abs(tmp[1]))
				rra_rrb(stack_b, "rrb\n");
		}
	}
	if (tmp[1] == 0)
		help_on_zero(tmp, stack_a);
}
