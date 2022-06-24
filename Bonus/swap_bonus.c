/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:28:22 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:16:33 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_list(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *head;
	tmp = tmp->next;
	tmp1 = tmp->next;
	tmp->next = *head;
	(*head)->next = tmp1;
	*head = tmp;
}

void	ft_sa_sb_bonus(t_list **head, char *num_of_stack)
{
	(void)num_of_stack;
	if (*head != NULL)
		swap_list(head);
}

void	ft_ss_bonus(t_list **stack_a, t_list **stack_b, char *num_of_stack)
{
	(void)num_of_stack;
	if (*stack_a != NULL && *stack_b != NULL)
	{
		swap_list(stack_a);
		swap_list(stack_b);
	}
}
