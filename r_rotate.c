/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:44 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/25 19:48:30 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void r_rotate(t_list **head)
{
    t_list *tmp;
    t_list *tmp1;

    tmp = *head;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp->next->next = *head;
    tmp1 = tmp->next;
    tmp->next = NULL;
    *head = tmp1;
}

void rra_rrb(t_list **head, char *num_of_stack)
{
    r_rotate(head);
    ft_putstr_fd(num_of_stack, 1);
}

void rrr(t_list **stack_a, t_list **stack_b, char *num_of_stack)
{
    r_rotate(stack_a);
    r_rotate(stack_b);
    ft_putstr_fd(num_of_stack, 1);
}