/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:09:46 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 01:09:51 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2_num(t_list **stack_a)
{
	sa_sb(stack_a, "sa\n");
}

void	sort_4_num(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	min;
	int	i;

	min = min_in_stack(*stack_a);
	index = position(stack_a, min);
	if (index == 0)
		push_b(stack_a, stack_b);
	if (index > (count_node(*stack_a) / 2) && index != 0)
	{
		i = 0;
		while (i++ < (count_node(*stack_a) - index))
			rra_rrb(stack_a, "rra\n");
		push_b(stack_a, stack_b);
	}
	if (index <= (count_node(*stack_a) / 2) && index != 0)
	{
		i = 0;
		while (i++ < index)
			ra_rb(stack_a, "ra\n");
		push_b(stack_a, stack_b);
	}
	sort_3_num(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5_num(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	min;
	int	i;

	min = min_in_stack(*stack_a);
	index = position(stack_a, min);
	if (index == 0)
		push_b(stack_a, stack_b);
	if (index > (count_node(*stack_a) / 2) && index != 0)
	{
		i = 0;
		while (i++ < (count_node(*stack_a) - index))
			rra_rrb(stack_a, "rra\n");
		push_b(stack_a, stack_b);
	}
	if (index <= (count_node(*stack_a) / 2) && index != 0)
	{
		i = 0;
		while (i++ < index)
			ra_rb(stack_a, "ra\n");
		push_b(stack_a, stack_b);
	}
	index_stack(*stack_a);
	sort_4_num(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	ft_sort_mine(t_list **stack_a, t_list **stack_b, int ac)
{
	if (ac == 3)
		sort_2_num(stack_a);
	if (ac == 4)
		sort_3_num(stack_a);
	if (ac == 5)
		sort_4_num(stack_a, stack_b);
	if (ac == 6)
		sort_5_num(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_help	*list;

	stack_a = initial_stack(ac, av);
	if (ac <= 2)
		exit(1);
	stack_b = NULL;
	ft_check_sorted(stack_a);
	index_stack(stack_a);
	if (ac <= 6)
		ft_sort_mine(&stack_a, &stack_b, ac);
	if (ac >= 7)
	{
		send_min_to_top(&stack_a);
		list = find_lis(stack_a);
		split_stacks(&stack_a, &stack_b, list);
		index_stack(stack_a);
		index_stack(stack_b);
		big_sort(&stack_a, &stack_b);
		send_min_to_top(&stack_a);
	}
	return (0);
}
