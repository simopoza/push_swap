/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:09:11 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/18 12:59:43 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void sort_3_num(t_list **stack_a)
{
	int data;

	data = (*stack_a)->next->next->data;
	if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data < data)
	{
		if ((*stack_a)->data < data)
			sa_sb(stack_a, "sa\n");
		if ((*stack_a)->data > data)
			ra_rb(stack_a, "ra\n");
	}
	if ((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->next->data > data)
	{
		if ((*stack_a)->data < data)
		{
			sa_sb(stack_a, "sa\n");
			ra_rb(stack_a, "ra\n");
		}
		if ((*stack_a)->data > data)
			rra_rrb(stack_a, "rra\n");
	}
	if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next->data > data)
	{
		sa_sb(stack_a, "sa\n");
		rra_rrb(stack_a, "rra\n");
	}
}

void ft_check_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data < stack_a->next->data)
			stack_a = stack_a->next;
		else
			return ;
	}
	exit (0);
}

bool is_number(char num[])
{
	int i;
	
	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i = 1;
	while (num[i] != 0)
	{
		if (!ft_isdigit(num[i]))
			return false;
		i++;
	}
	return true;
}

t_list *initial_stack(int ac, char *av[])
{
	t_list *top;
	int i;

	top = NULL;
	i = ac;
	while (i-- > 1)
	{
		--ac;
		if (!is_number(av[ac]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		add_at_front(&top, ft_atoi(av[ac]));
	}
	return (top);
}
