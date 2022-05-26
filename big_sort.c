/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:00:49 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/25 22:32:09 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int position(t_list **stack, int data)
{
	t_list *tmp;
	int index;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->data == data)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

int moves_a(int pos_a, t_list *stack_a)
{
	int moves;

	if (pos_a > count_node(stack_a) / 2)
		moves = -(count_node(stack_a) - pos_a + 1);
	else
		moves = pos_a - 1;
	return (moves);
}

int	moves_in_a(int data, t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		pos_a;
	int		i;

	i = 2;
	tmp1 = stack_a;
	tmp = ft_lstlastt(tmp1);
	if (data > max_in_stack(stack_a))
	{
		pos_a = position(&stack_a, max_in_stack(stack_a)) + 2;
		return (moves_a(pos_a, stack_a));
	}
	if (stack_a->data > data && data > tmp->data)
		return (0);
	if (stack_a->data < data && stack_a->next->data > data)
		return (moves_a(i, stack_a));
	tmp1 = stack_a->next;
	while (tmp1->next)
	{
		if (tmp1->data < data && tmp1->next->data > data)
			pos_a = i + 1;
		i++;
		tmp1 = tmp1->next;
	}
	return (moves_a(pos_a, stack_a));
}

int	moves_in_b(int pos_b, t_list *stack_b)
{
	int moves;

	if (pos_b > count_node(stack_b) / 2)
		moves = - (count_node(stack_b) - pos_b + 1);
	else
		moves = pos_b - 1;
	return (moves);
}


t_move	*initial_move(t_move *t)
{
	t = malloc(sizeof(t_move));
	if (!t)
	{
		ft_putstr_fd("Error allocation\n", 0);
		return (NULL);
	}
	return (t);
}

void	initial_tmp(int *tmp, int pos_a)
{
	tmp[0] = pos_a;
	tmp[1] = 0;
}



int	ft_int_max(int pos_a, int pos_b)
{
	if (pos_a >= pos_b)
		return (pos_a);
	else
		return (pos_b);
}

int *best_moves(t_list **stack_a, t_list **stack_b, int *tmp)
{
	t_list	*tmp_b;
	t_move	*t;
	int		i;

	t = NULL;
	t = initial_move(t);
	t->moves = abs(moves_in_a((*stack_b)->data, (*stack_a)));
	initial_tmp(tmp, moves_in_a((*stack_b)->data, (*stack_a)));
	i = 2;
	tmp_b = (*stack_b)->next;
	while (tmp_b)
	{
		t->pos_a = moves_in_a(tmp_b->data, *stack_a);
		t->pos_b = moves_in_b(i, *stack_b);
		if (t->pos_a * t->pos_b > 0)
			t->best = ft_int_max(abs(t->pos_a), abs(t->pos_b));
		else
			t->best = abs(t->pos_a) + abs(t->pos_b);
		if (t->best < t->moves)
		{
			t->moves = t->best;
			tmp[0] = t->pos_a;
			tmp[1] = t->pos_b;
		}
		tmp_b = tmp_b->next;
		i++;
	}
	return (tmp);
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
	{
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
}

void apply_on_top(int tmp_a, int tmp_b, t_list **stack_a, t_list **stack_b)
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

void apply_on_bottom(int tmp_a, int tmp_b, t_list **stack_a, t_list **stack_b)
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

void apply_on_same_sign(int *tmp, t_list **stack_a, t_list **stack_b)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = abs(tmp[0]);
	tmp_b = abs(tmp[1]);
	if (tmp[0] > 0)
		apply_on_top(tmp_a, tmp_b, stack_a, stack_b);
	if (tmp[0] < 0)
		apply_on_bottom(tmp_a, tmp_b, stack_a, stack_b);
}

void apply_on_different_sign(int *tmp, t_list **stack_a, t_list **stack_b)
{
	int tmp_a;
	int tmp_b;

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

void apply_those_moves(int *tmp, t_list **stack_a, t_list **stack_b)
{
	if (tmp[0] * tmp[1] == 0)
		apply_on_zero(tmp, stack_a, stack_b);
	if ((tmp[0] * tmp[1]) < 0)
		apply_on_different_sign(tmp, stack_a, stack_b);
	if (tmp[0] * tmp[1] > 0)
		apply_on_same_sign(tmp, stack_a, stack_b);
	push_a(stack_a, stack_b);
	index_stack(*stack_a);
	index_stack(*stack_b);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int *tmp;
	int len;
	int i;

	tmp = malloc (sizeof (int) * 2);
	if (!tmp)
	{
		ft_putstr_fd("Error allocation\n", 0);
		return ;
	}
	i = 0;
	len = count_node((*stack_b));
	while (i < len)
	{
		tmp = best_moves(stack_a, stack_b, tmp);
		apply_those_moves(tmp, stack_a, stack_b);
		i++;
	}
}