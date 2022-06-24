/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:19:52 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 01:13:17 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	*initial_tmp(int pos_a)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * 2);
	if (!tmp)
	{
		ft_putstr_fd("Error allocation\n", 0);
		return (NULL);
	}
	tmp[0] = pos_a;
	tmp[1] = 0;
	return (tmp);
}

int	ft_int_max(int pos_a, int pos_b)
{
	if (pos_a >= pos_b)
		return (pos_a);
	else
		return (pos_b);
}

int	help_best_moves(t_move *t)
{
	t->moves = t->best;
	t->tmp[0] = t->pos_a;
	t->tmp[1] = t->pos_b;
	return (t->moves);
}

int	*best_moves(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	t_move	*t;
	int		i;

	t = NULL;
	t = initial_move(t);
	t->moves = abs(moves_in_a((*stack_b)->data, (*stack_a)));
	t->tmp = initial_tmp(moves_in_a((*stack_b)->data, (*stack_a)));
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
			t->moves = help_best_moves(t);
		tmp_b = tmp_b->next;
		i++;
	}
	return (t->tmp);
}
