/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:27:16 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:18:00 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *head;
	tmp1 = tmp->next;
	tmp->next = NULL;
	*head = tmp1;
}

void	ft_rra_rrb_bonus(t_list **head, char *num_of_stack)
{
	(void)num_of_stack;
	if (*head != NULL)
		r_rotate(head);
}

void	ft_rrr_bonus(t_list **stack_a, t_list **stack_b, char *num_of_stack)
{
	(void)num_of_stack;
	if (*stack_a != NULL && *stack_b != NULL)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
}
