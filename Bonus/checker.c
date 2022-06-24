/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:25:51 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 18:44:17 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_sorted_bonus(t_list *stack_a, t_list *stack_b)
{
	if (stack_a != NULL)
	{
		while (stack_a->next)
		{
			if (stack_a->data < stack_a->next->data)
				stack_a = stack_a->next;
			else
			{
				ft_putstr_fd("KO\n", 1);
				return ;
			}
		}
		if (stack_b == NULL)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 1);
	exit(0);
}

void	help_checker_moves(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
		ft_rr_bonus(stack_a, stack_b, "rr\n");
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_rra_rrb_bonus(stack_a, "rra\n");
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_rra_rrb_bonus(stack_b, "rrb\n");
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		ft_rrr_bonus(stack_a, stack_b, "rrr\n");
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_sa_sb_bonus(stack_a, "sa\n");
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_sa_sb_bonus(stack_b, "sb\n");
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ft_ss_bonus(stack_a, stack_b, "ss\n");
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push_a_bonus(stack_a, stack_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push_b_bonus(stack_a, stack_b);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}

void	checker_moves(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_ra_rb_bonus(stack_a, "ra\n");
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_ra_rb_bonus(stack_b, "rb\n");
	else
		help_checker_moves(str, stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;

	stack_a = initial_stack(ac, av);
	if (ac < 2)
		exit(1);
	stack_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		checker_moves(str, &stack_a, &stack_b);
		free(str);
		str = get_next_line(0);
	}
	ft_check_sorted_bonus(stack_a, stack_b);
	return (0);
}
