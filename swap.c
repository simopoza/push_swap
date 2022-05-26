/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:17 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/25 19:48:09 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_list(t_list **head)
{
    t_list *tmp;
    t_list *tmp1;

    tmp = *head;
    tmp = tmp->next;
    tmp1 = tmp->next;
    tmp->next = *head;
    (*head)->next = tmp1;
    *head = tmp;
}

void sa_sb(t_list **head, char *num_of_stack)
{
    if ((is_empty(*head) != 0) && (count_node(*head) > 1))
    {
        swap_list(head);
        ft_putstr_fd(num_of_stack, 1);
    }
}

void ss(t_list **stack_a, t_list **stack_b, char *num_of_stack)
{
    if (((is_empty(*stack_a) == 0) && (count_node(*stack_a) < 1)) || //
        ((is_empty(*stack_b) == 0) && (count_node(*stack_b) < 1)))
        return;
    else
    {
        swap_list(stack_a);
        swap_list(stack_b);
        ft_putstr_fd(num_of_stack, 1);
    }
}