/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:26:58 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:17:05 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *head;
	tmp1 = (*head)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	*head = tmp1;
}

void	ft_ra_rb_bonus(t_list **head, char *num_of_stack)
{
	(void)num_of_stack;
	if (*head != NULL)
		rotate(head);
}

void	ft_rr_bonus(t_list **stack_a, t_list **stack_b, char *num_of_stack)
{
	(void)num_of_stack;
	if (*stack_a != NULL && *stack_b != NULL)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
