/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:39 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/25 19:48:22 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **head)
{
    t_list *tmp;
    t_list *tmp1;

    tmp = *head;
    tmp1 = (*head)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *head;
    (*head)->next = NULL;
    *head = tmp1;
}

void ra_rb(t_list **head, char *num_of_stack)
{
    rotate(head);
    ft_putstr_fd(num_of_stack, 1);
}

void rr(t_list **stack_a, t_list **stack_b, char *num_of_stack)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd(num_of_stack, 1);
}